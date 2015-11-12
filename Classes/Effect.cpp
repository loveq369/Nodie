#include "Effect.h"
#include "AnimateManager.h"
//#include "ParticleManager.h"
#include "util/ReadUtil.h"
USING_NS_CC;


	Effect::Effect(void)
{
	m_sElapsed = 0.0f;
	m_dElapsed = 0.0f;
	m_displayNode = NULL;
	m_isPlaying = false;
}

Effect::~Effect(void)
{
	removeParticle();
	clear();
}
void Effect::clear()
{
	CC_SAFE_RELEASE_NULL(m_displayNode);
}
void Effect::stop()
{
	if (m_displayNode)
	{
		m_displayNode->stopAllActions();
	}
}
void Effect::reset()
{
	m_sElapsed = 0;
	m_dElapsed = 0;
}
void Effect::tick(float dt)
{
	if (m_effectInfo.m_effectParent == NULL)
	{
		return;
	}
	m_sElapsed += dt;
	if (m_sElapsed >= m_effectInfo.m_configData.m_startTime)//开始播放
	{
		if (m_isPlaying)
		{
			if (m_effectInfo.m_configData.m_duration <= 0)
			{
				//无限播放
			}
			else
			{
				m_dElapsed += dt;
				if (m_dElapsed >= m_effectInfo.m_configData.m_duration)//删除
				{
					removeParticle();
				}
			}
		}
		else
		{
			m_isPlaying = true;
			addParticle();
		}
	}
}

void Effect::init()
{
	if (m_displayNode)
	{
		return;
	}
	switch (m_effectInfo.m_configData.m_particleType)
	{
	case EFFECT_PARTICLE_TYPE_PARTICLE:
		{
			/*m_displayNode = ParticleManager::getInstance().getParticle((m_effectInfo.m_configData.m_particleName).c_str());
			m_displayNode->retain();*/
			break;
		}
	case EFFECT_PARTICLE_TYPE_ANIM:
		{
			m_displayNode = CCSprite::create();
			m_displayNode->retain();
			break;
		}
	}
}

//设置目标特效的真正播放位置
void setEffectPosition(CCNode* particle, EffectInfo& effectInfo)
{
	switch (effectInfo.m_part)
	{
	case EFFECT_PART_HEAD:
	case EFFECT_PART_TOP:
		particle->setPositionY(effectInfo.m_targetSize.height);
		break;
	case EFFECT_PART_HEART:
		particle->setPositionY(effectInfo.m_targetSize.height*2/3);
		break;
	case EFFECT_PART_HAND:
		particle->setPositionY(effectInfo.m_targetSize.height/2);
		break;
	case EFFECT_PART_LEG:
		particle->setPositionY(effectInfo.m_targetSize.height/3);
		break;
	case EFFECT_PART_BUTTOM:
		particle->setPositionY(0);
		break;
	default:
		break;
	}
}
//获得飞行特效的真正目标点
void getFlyEffectPosition(EffectInfo& effectInfo)
{
	switch (effectInfo.m_part)
	{
	case EFFECT_PART_HEART:
		{
			effectInfo.m_startPixelPos.y += effectInfo.m_ownerSize.height*2/3;
			effectInfo.m_endPixelPos.y += effectInfo.m_targetSize.height*2/3;
		}
		break;
	case EFFECT_PART_HAND:
		{
			effectInfo.m_startPixelPos.y += effectInfo.m_ownerSize.height/2;
			effectInfo.m_endPixelPos.y += effectInfo.m_targetSize.height/2;
		}
		break;
	case EFFECT_PART_LEG:
		{
			effectInfo.m_startPixelPos.y += effectInfo.m_ownerSize.height/3;
			effectInfo.m_endPixelPos.y += effectInfo.m_targetSize.height/3;
		}
		break;
	case EFFECT_PART_HEAD:
	case EFFECT_PART_TOP:
		{
			effectInfo.m_startPixelPos.y += effectInfo.m_ownerSize.height;
			effectInfo.m_endPixelPos.y += effectInfo.m_targetSize.height;
		}
		break;
	case EFFECT_PART_BUTTOM:
		break;
	default:
		break;
	}
}

void Effect::addParticle()
{
	if (!m_displayNode || !m_effectInfo.m_effectParent)
	{
		return;
	}
	switch (m_effectInfo.m_type)
	{
	case EFFECT_TYPE_TARGET:
		{
			switch (m_effectInfo.m_configData.m_particleType)
			{
			case EFFECT_PARTICLE_TYPE_PARTICLE:
				{
					setEffectPosition(m_displayNode, m_effectInfo);
					m_effectInfo.m_effectParent->addChild(m_displayNode, m_effectInfo.m_zorder);
					break;
				}
			case EFFECT_PARTICLE_TYPE_ANIM:
				{
					CCSequence* seq = AnimateManager::getInstance().getSequence((m_effectInfo.m_configData.m_particleName).c_str(), DEFAULT_ANIMATE_NAME, NULL);
					if (seq)
					{
						if (m_effectInfo.m_configData.m_duration <= 0)
						{
							//无限播放
							m_displayNode->runAction(CCRepeatForever::create(seq));
							setEffectPosition(m_displayNode, m_effectInfo);
							m_effectInfo.m_effectParent->addChild(m_displayNode, m_effectInfo.m_zorder);
						}
						else
						{
							m_displayNode->runAction(seq);
							setEffectPosition(m_displayNode, m_effectInfo);
							m_effectInfo.m_effectParent->addChild(m_displayNode, m_effectInfo.m_zorder);
						}
					}
					break;
				}
			}
			break;
		}
	case EFFECT_TYPE_FLY:
		{
			if (m_effectInfo.m_flySpeed>0)
			{
				switch (m_effectInfo.m_configData.m_particleType)
				{
				case EFFECT_PARTICLE_TYPE_PARTICLE:
					break;
				case EFFECT_PARTICLE_TYPE_ANIM:
					{
						CCSequence* seq = AnimateManager::getInstance().getSequence((m_effectInfo.m_configData.m_particleName).c_str(), DEFAULT_ANIMATE_NAME, NULL);
						if (seq)
						{
							m_displayNode->runAction(seq);
						}
					}
					break;
				}
				startFly();
				m_effectInfo.m_effectParent->addChild(m_displayNode, m_effectInfo.m_zorder);
			}
			break;
		}
	case EFFECT_TYPE_GROUND:
		{
			switch (m_effectInfo.m_configData.m_particleType)
			{
			case EFFECT_PARTICLE_TYPE_PARTICLE:
				break;
			case EFFECT_PARTICLE_TYPE_ANIM:
				{
					CCSequence* seq = AnimateManager::getInstance().getSequence((m_effectInfo.m_configData.m_particleName).c_str(), DEFAULT_ANIMATE_NAME, NULL);
					if (seq)
					{
						if (m_effectInfo.m_configData.m_duration <= 0)
						{
							//无限播放
							m_displayNode->runAction(CCRepeatForever::create(seq));
						}
						else
						{
							m_displayNode->runAction(seq);
						}
					}
				}
				break;
			}
			m_displayNode->setPosition(m_effectInfo.m_startPixelPos);
			m_effectInfo.m_effectParent->addChild(m_displayNode, m_effectInfo.m_zorder);
			break;
		}
	}
}
void Effect::startFly()
{
	getFlyEffectPosition(m_effectInfo);
	float duration = m_effectInfo.m_startTileCoord.distance(m_effectInfo.m_endTileCoord)/m_effectInfo.m_flySpeed;
	CCMoveTo* moveAction = CCMoveTo::create(duration,m_effectInfo.m_endPixelPos);
	m_displayNode->setPosition(m_effectInfo.m_startPixelPos);
	CCCallFunc* flyCallback = CCCallFunc::create(this, callfunc_selector(Effect::flyOverCallback));
	m_displayNode->runAction(CCSequence::create(moveAction, flyCallback, NULL));
	float yDegree = (atan2((m_effectInfo.m_endPixelPos.y-m_effectInfo.m_startPixelPos.y), (m_effectInfo.m_endPixelPos.x-m_effectInfo.m_startPixelPos.x)))*57.3f;
	m_displayNode->setRotation(-yDegree);
}
void Effect::flyOverCallback()
{
	if (m_effectInfo.m_isFlyRepeat)
	{
		startFly();
	}
	else
	{
		m_effectInfo.m_configData.m_duration = 0.1f;
		removeParticle();
	}
}
void Effect::removeParticle()
{
	if (m_displayNode && m_effectInfo.m_effectParent)
	{
		stop();
		m_effectInfo.m_effectParent->removeChild(m_displayNode, true);
	}
}
bool Effect::isDead()
{
	if (m_effectInfo.m_configData.m_duration>0)
	{
		return (this->m_dElapsed >= m_effectInfo.m_configData.m_duration);
	}
	else
	{
		return false;
	}
}
void Effect::setFlySpeed(int flySpeed)
{
	m_effectInfo.m_flySpeed = flySpeed;
}
void Effect::setPart(int8 part)
{
	m_effectInfo.m_part = part;
}
void Effect::setEffectInfo(EffectInfo& ei)
{
	m_effectInfo = ei;
}


void EffectConfigData::encode( unsigned char*& data, unsigned long& pos )
{
	pos += readString(data, m_effectName);
	pos += readString(data, m_particleName);
	pos += readFloat(data, m_startTime);
	pos += readFloat(data, m_duration);
	pos += readInt8(data, m_particleType);
}
