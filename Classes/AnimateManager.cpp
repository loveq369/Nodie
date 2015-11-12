#include "AnimateManager.h"
#include "TextureManager.h"
#include "MacrosDefine.h"
#include "util/ReadUtil.h"
#include "util/byte_buffer.h"
#include "util/byteorder.h"
#include "tinyxml2/tinyxml2.h"
USING_NS_CC;


AnimateManager::AnimateManager()
{
	m_resFolderStr = "";
	m_resTypeStr = ".pvr.ccz";
}
AnimateManager::~AnimateManager()
{
	std::map<std::string, ObjectAllAnimations*>::iterator itr;
	CLEAR_UP_MAP(m_animDataDic, itr);
}

void AnimateManager::parseObject(const char* filename)
{
	std::map<std::string, ObjectAllAnimations*>::iterator itr = m_animDataDic.find(filename);
	if (itr==m_animDataDic.end())
	{
		__parseObject(filename);
	}
}
ObjectAllAnimations* AnimateManager::__parseObject(const char* filename)
{
	unsigned long fileLen = 0;
	unsigned char *fileData = NULL;
	fileData = CCFileUtils::sharedFileUtils()->getFileData(filename, "rb", (ssize_t *)(&fileLen));
	if (fileData)
	{
		unsigned char* temp = fileData;
		unsigned long pos = 0;
		ObjectAllAnimations* object = new ObjectAllAnimations();
		object->encode(fileData, pos);
		m_animDataDic.insert(std::map<std::string, ObjectAllAnimations*>::value_type(filename, object));
		CC_SAFE_DELETE_ARRAY(temp);
		return object;
	}
	return NULL;
}

void AnimateManager::parseXML(const char *fileName)
{
	std::string filePath=CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName);
	//std::string filePath = FileUtils::getInstance()->getWritablePath() + fileName;
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
	tinyxml2::XMLError errorId = pDoc->LoadFile(filePath.c_str());

	if (errorId != 0) {
		//xml格式错误
		return;
	}
	ObjectAllAnimations* object = new ObjectAllAnimations();
	tinyxml2::XMLElement *rootEle = pDoc->RootElement();
	tinyxml2::XMLElement * listnum = rootEle->FirstChildElement("listnum");
	std::string strlistnum=listnum->GetText();
	short shortlistnum=(short)std::atoi(strlistnum.c_str());
	tinyxml2::XMLElement * list = rootEle->FirstChildElement("list");
	tinyxml2::XMLElement *listitem = list->FirstChildElement("listitem");
	while ( listitem ) {
		tinyxml2::XMLElement * fileName = listitem->FirstChildElement("fileName");
		std::string strFileName=fileName->GetText();
		ItemPlistData  listdata(strFileName);
		tinyxml2::XMLElement * picItemNum = listitem->FirstChildElement("picItemNum");
		std::string strPicItemNum = picItemNum->GetText();
		short shortPicItemNum=(short)std::atoi(strPicItemNum.c_str());
		tinyxml2::XMLElement * picItem = listitem->FirstChildElement("picItem");
		while (picItem)
		{
			tinyxml2::XMLElement * x = picItem->FirstChildElement("x");
			std::string strx = x->GetText();
			short shortx=(short)std::atoi(strx.c_str());
			tinyxml2::XMLElement * y = picItem->FirstChildElement("y");
			std::string stry = y->GetText();
			short shorty=(short)std::atoi(stry.c_str());
			tinyxml2::XMLElement * w = picItem->FirstChildElement("w");
			std::string strw = w->GetText();
			short shortw=(short)std::atoi(strw.c_str());
			tinyxml2::XMLElement * h = picItem->FirstChildElement("h");
			std::string strh = h->GetText();
			short shorth=(short)std::atoi(strh.c_str());
			tinyxml2::XMLElement * offesetx = picItem->FirstChildElement("offesetx");
			std::string stroffesetx = offesetx->GetText();
			short shortoffesetx=(short)std::atoi(stroffesetx.c_str());
			tinyxml2::XMLElement * offesety = picItem->FirstChildElement("offesety");
			std::string stroffesety = offesety->GetText();
			short shortoffesety=(short)std::atoi(stroffesety.c_str());
			tinyxml2::XMLElement * rateted = picItem->FirstChildElement("rateted");
			std::string strrateted = rateted->GetText();
			short shortrateted=(short)std::atoi(strrateted.c_str());
			bool isRateted=shortrateted==1;
			PlistFrame listFrame(CCRect(shortx,shorty,shortw,shorth),CCPoint(shortoffesetx,shortoffesety),isRateted);
			listdata.pushBack(listFrame);
			picItem = picItem->NextSiblingElement();
		}
		object->pushBackItemPlistData(listdata);
		listitem = listitem->NextSiblingElement();
	}
	tinyxml2::XMLElement * animnum = rootEle->FirstChildElement("animnum");
	std::string stranimnum=animnum->GetText();
	short shortanimnum=(short)std::atoi(stranimnum.c_str());
	tinyxml2::XMLElement * animate = rootEle->FirstChildElement("animate");
	while ( animate ) {
		tinyxml2::XMLElement * animateName = animate->FirstChildElement("animateName");
		std::string stranimateName = animateName->GetText();
		tinyxml2::XMLElement * delay = animate->FirstChildElement("delay");
		std::string strdelay = delay->GetText();
		float floatdelay=std::atof(strdelay.c_str());
		tinyxml2::XMLElement * flipx = animate->FirstChildElement("flipx");
		std::string strflipx = flipx->GetText();
		short shortflipx=(short)std::atoi(strflipx.c_str());
		tinyxml2::XMLElement * flipy = animate->FirstChildElement("flipy");
		std::string strflipy = flipy->GetText();
		short shortflipy=(short)std::atoi(strflipy.c_str());
		tinyxml2::XMLElement * frameNum = animate->FirstChildElement("frameNum");
		std::string strframeNum = frameNum->GetText();
		short shortframeNum=(short)std::atoi(strframeNum.c_str());
		tinyxml2::XMLElement * frameItem = animate->FirstChildElement("frameItem");
		ItemAnimateData animateData(floatdelay,shortflipx==1,shortflipy==1,-1000);
		while (frameItem)
		{
			tinyxml2::XMLElement * picIndex = frameItem->FirstChildElement("picIndex");
			std::string strpicIndex = picIndex->GetText();
			short shortpicIndex=(short)std::atoi(strpicIndex.c_str());
			tinyxml2::XMLElement * posIndex = frameItem->FirstChildElement("posIndex");
			std::string strposIndex = posIndex->GetText();
			short shortposIndex=(short)std::atoi(strposIndex.c_str());
			frameItem=frameItem->NextSiblingElement();
			InfoIndex infoIndex={shortpicIndex,shortposIndex};
			animateData.pushBack(infoIndex);
		}
		object->pushBackItemAnimateData(std::map<std::string,ItemAnimateData>::value_type(stranimateName,animateData));
		object->writeToFile("D://1001.anim");
		animate = animate->NextSiblingElement();
	}
	m_animDataDic.insert(std::map<std::string, ObjectAllAnimations*>::value_type(fileName,object));
	delete pDoc;

}
int AnimateManager::getFrameHeight(const char* filename, const char* animateName)
{
	ObjectAllAnimations* object = getObjectAnimationsByFilename(filename);
	if (object)
	{
		std::map<std::string, ItemAnimateData>::iterator animateDataItr = object->allAnimations.find(animateName);
		if (animateDataItr!=object->allAnimations.end())
		{
			ItemAnimateData* animateData = &(animateDataItr->second);
			std::vector<InfoIndex>::iterator infoIdxListItr = animateData->m_infoIndexList.begin();
			ItemPlistData* plistData = &(object->infoPlistList[(*infoIdxListItr).m_picIndex]);
			PlistFrame* tpf = &(plistData->m_plistFrameList[(*infoIdxListItr).m_posIndex]);
			return tpf->m_frame.size.height/2+tpf->m_offset.y;
		}
	}
	return 0;
}

cocos2d::CCSequence* AnimateManager::getSequence( const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc )
{
	ItemAnimateData* animData = NULL;
	CCAnimation* animation = getAnimation(filename, animateName, animData);
	if (animation && animData)
	{
		return createSequence(animation, callFunc, animData->m_delay, animData->m_flipX, animData->m_flipY);
	}
	return NULL;
}

cocos2d::CCSequence* AnimateManager::getSequence( const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc, float delay, bool flipX, bool flipY )
{
	ItemAnimateData* animData = NULL;
	CCAnimation* animation = getAnimation(filename, animateName, animData);
	if (animation && animData)
	{
		if (delay<0)
		{
			delay = animation->getDelayPerUnit();
		}
		return createSequence(animation, callFunc, delay, flipX, flipY);
	}
	return NULL;
}

cocos2d::CCSequence* AnimateManager::getSequence( const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc, float delay )
{
	ItemAnimateData* animData = NULL;
	CCAnimation* animation = getAnimation(filename, animateName, animData);
	if (animation && animData)
	{
		if (delay<0)
		{
			delay = animation->getDelayPerUnit();
		}
		return createSequence(animation, callFunc, delay, animData->m_flipX, animData->m_flipY);
	}
	return NULL;
}

cocos2d::CCSequence* AnimateManager::getSequence( const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc, bool flipX )
{
	ItemAnimateData* animData = NULL;
	CCAnimation* animation = getAnimation(filename, animateName, animData);
	if (animation && animData)
	{
		return createSequence(animation, callFunc, animData->m_delay, flipX, animData->m_flipY);
	}
	return NULL;
}

CCSequence* AnimateManager::createSequence(cocos2d::CCAnimation* animation, CCCallFunc* callFunc, float delay, bool flipX, bool flipY)
{
	CCArray* actions = CCArray::create();
	actions->addObject(CCFlipX::create(flipX));
	actions->addObject(CCFlipY::create(flipY));
	animation->setDelayPerUnit(delay);
	actions->addObject(CCAnimate::create(animation));
	if (callFunc)
	{
		actions->addObject(callFunc);
	}

	CCSequence* sequence = createSequence(actions);
	actions->removeAllObjects();

	return sequence;
}

CCSequence* AnimateManager::createSequence(CCArray *actions)
{
	CC_ASSERT(actions->count()>1);
	CCSequence *seq = CCSequence::createWithTwoActions((CCFiniteTimeAction*)actions->objectAtIndex(0),
		(CCFiniteTimeAction*)actions->objectAtIndex(1));
	for (unsigned int i = 2; i < actions->count(); ++i) {
		seq = CCSequence::createWithTwoActions(seq, (CCFiniteTimeAction*)actions->objectAtIndex(i));
	}
	return seq;
}

cocos2d::CCAnimation* AnimateManager::getAnimation( const char* filename, const char* animateName, ItemAnimateData*& animateData )
{
	ObjectAllAnimations* object = getObjectAnimationsByFilename(filename);
	if (!object)
	{
		return NULL;
	}
	std::map<std::string, ItemAnimateData>::iterator itemAnimDataItr = object->allAnimations.find(animateName);
	if (itemAnimDataItr==object->allAnimations.end())
	{
		return NULL;
	}
	animateData = &(itemAnimDataItr->second);
	CCAnimation* animation = CCAnimationCache::sharedAnimationCache()->animationByName(animateName);
	if (animation)
	{
		return animation;
	}
	else
	{
		std::vector<InfoIndex>::iterator infoIdxListItr = animateData->m_infoIndexList.begin();
		std::vector<ItemPlistData>::iterator itemPlistItr;//动作文件所有plist数据
		std::vector<PlistFrame>::iterator plistFrameItr;//一个plist数据
		std::string picPath;//图片路径
		Vector<CCSpriteFrame*> spriteFrameVec;//动作spriteFrames
		for (;infoIdxListItr!=animateData->m_infoIndexList.end();infoIdxListItr++)
		{
			itemPlistItr = object->infoPlistList.begin()+(*infoIdxListItr).m_picIndex;
			picPath = CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(((*itemPlistItr).m_picFilename+m_resTypeStr).c_str(), filename);
			CCTexture2D* texture = TextureManager::getInstance().addImage(picPath.c_str());
			if (texture)
			{
				plistFrameItr = (*itemPlistItr).m_plistFrameList.begin()+(*infoIdxListItr).m_posIndex;
				if ((*plistFrameItr).m_frame.size.width>0 && (*plistFrameItr).m_frame.size.height>0)
				{
					CCSpriteFrame* spriteFrame = CCSpriteFrame::createWithTexture(texture, (*plistFrameItr).m_frame, (*plistFrameItr).m_rateted, (*plistFrameItr).m_offset, (*plistFrameItr).m_frame.size);
					spriteFrameVec.pushBack(spriteFrame);
				}
			}
		}
		if (spriteFrameVec.size()>0)
		{
			animation = CCAnimation::createWithSpriteFrames(spriteFrameVec, animateData->m_delay);
			std::string animationName = filename;
			animationName += animateName;
			CCAnimationCache::sharedAnimationCache()->addAnimation(animation, animationName.c_str());
	
			return animation;
		}
		return NULL;
	}
}

ObjectAllAnimations* AnimateManager::getObjectAnimationsByFilename( const char* filename )
{
	if (filename==NULL || 0==strcmp(filename,""))
	{
		return NULL;
	}
	std::map<std::string, ObjectAllAnimations*>::iterator itr = m_animDataDic.find(filename);
	if (itr==m_animDataDic.end())
	{
		return __parseObject(filename);
	}
	else
	{
		return itr->second;
	}
}

cocos2d::CCSpriteFrame* AnimateManager::getFirstSpriteFrame( const char* filename, const char* animateName, bool& isFlipX )
{
	ObjectAllAnimations* object = getObjectAnimationsByFilename(filename);
	if (!object)
	{
		return NULL;
	}
	std::map<std::string, ItemAnimateData>::iterator animateDataItr = object->allAnimations.find(animateName);
	if (animateDataItr==object->allAnimations.end())
	{
		return NULL;
	}
	ItemAnimateData* animData = &(animateDataItr->second);
	isFlipX = animData->m_flipX;
	std::string animationName = filename;
	animationName += animateName;
	CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(animationName.c_str());
	if (spriteFrame)
	{
		return spriteFrame;
	}
	else
	{
		CCAnimation* animation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName.c_str());
		if (animation)
		{
			CCAnimationFrame* frame = (CCAnimationFrame*)animation->getFrames().at(0);
			if (frame)
			{
				return frame->getSpriteFrame();
			}
		}
		std::vector<InfoIndex>::iterator infoIdxListItr = animData->m_infoIndexList.begin();
		std::vector<ItemPlistData>::iterator itemPlistItr;//动作文件所有plist数据
		std::vector<PlistFrame>::iterator plistFrameItr;//一个plist数据
		std::string picPath;//图片路径
		itemPlistItr = object->infoPlistList.begin()+(*infoIdxListItr).m_picIndex;
		picPath = CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(((*itemPlistItr).m_picFilename+m_resTypeStr).c_str(), filename);
		CCTexture2D* texture = TextureManager::getInstance().addImage(picPath.c_str());
		if (texture)
		{
			plistFrameItr = (*itemPlistItr).m_plistFrameList.begin()+(*infoIdxListItr).m_posIndex;
			if ((*plistFrameItr).m_frame.size.width>0 && (*plistFrameItr).m_frame.size.height>0)
			{
				CCSpriteFrame* spriteFrame =CCSpriteFrame::createWithTexture(texture, (*plistFrameItr).m_frame, (*plistFrameItr).m_rateted, (*plistFrameItr).m_offset, (*plistFrameItr).m_frame.size);
				CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(spriteFrame, animationName.c_str());
				spriteFrame->release();
				return spriteFrame;
			}
		}
	}
	return NULL;
}

void AnimateManager::releaseSequence( const char* animateName )
{

}
PlistFrame::PlistFrame(cocos2d::CCRect frame,cocos2d::CCPoint offset,bool rateted)
{
	m_frame=frame;
	m_offset=offset;
	m_rateted=rateted;
}


void PlistFrame::encode( unsigned char*& data, unsigned long& pos )
{
	short x = 0;
	short y = 0;
	short w = 0;
	short h = 0;
	pos += readShort(data, x);
	pos += readShort(data, y);
	pos += readShort(data, w);
	pos += readShort(data, h);
	m_frame = cocos2d::CCRectMake(x,y,w,h);

	short px = 0;
	short py = 0;
	pos += readShort(data, px);
	pos += readShort(data, py);
	m_offset = ccp(px, py);

	pos += readBool(data, m_rateted);
}
ItemPlistData::ItemPlistData(std::string picFilename):m_picFilename(picFilename)
{
}

void ItemPlistData::pushBack(PlistFrame listFrame)
{
	m_plistFrameList.push_back(listFrame);
}

void ItemPlistData::encode( unsigned char*& data, unsigned long& pos )
{
	pos += readString(data, m_picFilename);

	short picItemNum = 0;//切片数目
	pos += readShort(data, picItemNum);

	for (int16 i=0;i<picItemNum;i++)
	{
		PlistFrame plistFrame;
		plistFrame.encode(data, pos);
		m_plistFrameList.push_back(plistFrame);
	}
}
ItemAnimateData::ItemAnimateData(float delay,bool flipX,bool flipY,int refrernceTimes):m_delay(delay),m_flipX(flipX)\
	,m_flipY(flipY),m_refernceTimes(refrernceTimes)
{

}

void ItemAnimateData::pushBack(InfoIndex infoIndex)
{
	m_infoIndexList.push_back(infoIndex);
}

void ItemAnimateData::encode( unsigned char*& data, unsigned long& pos )
{
	m_refernceTimes = -1000;
	pos += readFloat(data, m_delay);
	pos += readBool(data, m_flipX);
	pos += readBool(data, m_flipY);

	short frameNum = 0;
	pos += readShort(data, frameNum);
	for (int i=0;i<frameNum;i++)
	{
		InfoIndex infoIndex;
		pos += readShort(data, infoIndex.m_picIndex);
		pos += readShort(data, infoIndex.m_posIndex);
		m_infoIndexList.push_back(infoIndex);
	}
}
void ObjectAllAnimations::pushBackItemAnimateData(std::pair<std::string, ItemAnimateData> pairAniData)
{
	allAnimations.insert(pairAniData);
}
void ObjectAllAnimations::pushBackItemPlistData(ItemPlistData itemPlistData)
{
	infoPlistList.push_back(itemPlistData);
}
void ObjectAllAnimations::writeToFile(char* file)
{
	ByteBuffer buffer;
	short listnum=infoPlistList.size();
	buffer<<endian_swap2<short>(listnum);
	for (short i=0;i<listnum;i++)
	{
		buffer.putString(infoPlistList[i].m_picFilename);
		short framenum=infoPlistList[i].m_plistFrameList.size();
		buffer<<endian_swap2<short>(framenum);
		for (short j=0;j<framenum;j++)
		{
			buffer<<endian_swap2<short>((short)infoPlistList[i].m_plistFrameList[j].m_frame.getMinX());
			buffer<<endian_swap2<short>((short)infoPlistList[i].m_plistFrameList[j].m_frame.getMinY());
			buffer<<endian_swap2<short>((short)infoPlistList[i].m_plistFrameList[j].m_frame.size.width);
			buffer<<endian_swap2<short>((short)infoPlistList[i].m_plistFrameList[j].m_frame.size.height);
			buffer<<endian_swap2<short>((short)infoPlistList[i].m_plistFrameList[j].m_offset.x);
			buffer<<endian_swap2<short>((short)infoPlistList[i].m_plistFrameList[j].m_offset.y);
			buffer<<infoPlistList[i].m_plistFrameList[j].m_rateted;
		}
	}
	short animalnum=allAnimations.size();
	buffer<<endian_swap2<short>(animalnum);
	std::map<std::string,ItemAnimateData>::iterator it;
	for(it=allAnimations.begin();it!=allAnimations.end();++it)
	{
		buffer.putString((std::string)it->first);
		buffer<<endian_swap4<float>(it->second.m_delay);
		buffer<<it->second.m_flipX;
		buffer<<it->second.m_flipY;
		short indexnum=it->second.m_infoIndexList.size();
		buffer<<endian_swap2<short>(indexnum);
		for(int i=0;i<indexnum;i++)
		{
			buffer<<endian_swap2<short>(it->second.m_infoIndexList[i].m_picIndex);
			buffer<<endian_swap2<short>(it->second.m_infoIndexList[i].m_posIndex);
		}
	}
	FILE *a = fopen(file,"wb");
	fwrite(buffer.contents(),buffer.size(),1,a);
	fclose(a);
}
void ObjectAllAnimations::encode( unsigned char*& data, unsigned long& pos )
{
	short num;
	pos += readShort(data, num);//plist数目
	for (short i=0;i<num;i++)
	{
		ItemPlistData itemPlistData;
		itemPlistData.encode(data, pos);
		infoPlistList.push_back(itemPlistData);
	}
	pos += readShort(data, num);//动作数目
	std::string animateName;
	for (short i=0;i<num;i++)
	{
		pos += readString(data, animateName);
		ItemAnimateData itemAnimateData;
		itemAnimateData.encode(data, pos);
		allAnimations.insert(std::map<std::string, ItemAnimateData>::value_type(animateName, itemAnimateData));
	}
}
