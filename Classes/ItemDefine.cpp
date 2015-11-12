//#include "ItemDefine.h"
//#include "DataManager.h"
//#include "UIDefine.h"
//USING_NS_CC;
//
//ccColor3B getColorByQuality(int quality)
//{
//	switch (quality)
//	{
//	case ITEM_LANZHUANG:
//		return ccBLUE;
//	case ITEM_ZIZHUANG:
//		return ccMAGENTA;
//	case ITEM_JINZHUANG:
//		return ccc3(239,227,0);
//	default:
//		return CH_GREEN;
//	}
//}
//ccColor3B getFumoColorByKV(tKV kv)
//{
//	EnchantFumoColorConfigData* fumoColorData = DataManager::getInstance().getItemConfigManager()->getEnchantFumoColorDataById(kv.key);
//	if (fumoColorData)
//	{
//		std::vector<tPoint>::iterator itr = fumoColorData->colorList.begin();
//		unsigned int index = 0;
//		for (;itr!=fumoColorData->colorList.end();itr++, index++)
//		{
//			if (kv.intValue>=(*itr).x && kv.intValue<=(*itr).y)
//			{
//				switch (index)
//				{
//				case 0:
//					return ITEM_COLOR_1;
//				case 1:
//					return ITEM_COLOR_2;
//				case 2:
//					return ITEM_COLOR_3;
//				case 3:
//					return ITEM_COLOR_4;
//				case 4:
//					return ITEM_COLOR_5;
//				case 5:
//					return ITEM_COLOR_6;
//				}
//			}
//		}
//	}
//	return ccBLACK;
//}
//int getFumoQualityByKV(tKV kv)
//{
//	EnchantFumoColorConfigData* fumoColorData = DataManager::getInstance().getItemConfigManager()->getEnchantFumoColorDataById(kv.key);
//	if (fumoColorData)
//	{
//		std::vector<tPoint>::iterator itr = fumoColorData->colorList.begin();
//		unsigned int index = 0;
//		for (;itr!=fumoColorData->colorList.end();itr++, index++)
//		{
//			if (kv.intValue>=(*itr).x && kv.intValue<=(*itr).y)
//			{
//				return index;
//			}
//		}
//	}
//	return 0;
//}
//EnchantZhuanyiConfigData* getZhuanyiDataByLv(int sencondaryLv, int mainLv)
//{
//	std::map<int, EnchantZhuanyiConfigData*>* enchantZhuanyiDic = DataManager::getInstance().getItemConfigManager()->getEnchantZhuanyiData();
//	std::map<int, EnchantZhuanyiConfigData*>::iterator itr = enchantZhuanyiDic->begin();
//	for (;itr!=enchantZhuanyiDic->end();itr++)
//	{
//		if (itr->second->giveoutLv.x<=sencondaryLv && itr->second->giveoutLv.y>=sencondaryLv &&\
//			itr->second->getLv.x<=mainLv && itr->second->getLv.y>=mainLv)
//		{
//			return itr->second;
//		}
//	}
//	return NULL;
//}
//
//void updateGridItemByBaseItemData(GridItem * gridItem,BaseItemData * baseItemData)
//{
//	if (baseItemData)
//	{
//		updateGridItemByBaseItemData(gridItem,baseItemData,GRID_USED,0,0,0);
//	}
//	else
//	{
//		updateGridItemByBaseItemData(gridItem,NULL,GRID_FREE,0,0,0);
//	}
//}
//
//
//void updateGridItemByBaseItemData(GridItem * gridItem,BaseItemData * baseItemData,int status,int pos,int slot,int src)
//{
//	if (status==GRID_USED)
//	{
//		tGridData tgd;
//		tgd.id  = baseItemData->entry;
//		tgd.pos = pos;
//		tgd.slot = baseItemData->slot;
//		tgd.num = baseItemData->count;
//		CCString* wk_str = CCString::createWithFormat("ui/itemimage/%d.pvr.ccz", baseItemData->displayid);
//		tgd.url = wk_str->getCString();
//		tgd.status =status;
//		tgd.src =src;
//
//
//
//		gridItem->updateGrid(tgd);
//
//		gridItem->setIsLock(false);
//
//		//物品绑定，小锁
//		if (baseItemData->isbonded)
//		{
//			gridItem->setIsBinding(true);
//		}
//		else
//		{
//			gridItem->setIsBinding(false);
//		}
//		//数量label
//		if (baseItemData->count==1 ||baseItemData->count==0)   // 数量为0或者1不显示数量label
//		{
//			gridItem->showNumLabel(false);
//		}
//		else
//		{
//			gridItem->showNumLabel(true);
//		}
//
//		//内颜色框
//		gridItem->showColorRect(true,1);
//
//		switch(baseItemData->qualty)
//		{
//		case 0: 
//			{
//				gridItem->setColorRectColor(QUALTY_CCC3_0,1);  
//				break;
//			}
//		case 1:
//			{
//				gridItem->setColorRectColor(QUALTY_CCC3_1,1);  
//				break;
//			}
//		case 2:
//			{
//				gridItem->setColorRectColor(QUALTY_CCC3_2,1);  
//				break;
//			}
//		case 3:
//			{
//				gridItem->setColorRectColor(QUALTY_CCC3_3,1);
//				break;
//			}
//		case 4:
//			{
//				gridItem->setColorRectColor(QUALTY_CCC3_4,1);  
//				break;
//			}
//		case 5:
//			{
//				gridItem->setColorRectColor(QUALTY_CCC3_5,1);  
//				break;
//			}
//		default:
//			break;
//
//		}
//
//		//外框
//		gridItem->showColorRect(false,0); //点击显示
//		gridItem->setColorRectColor(ccc3(255,255,0),0);     //黄色
//
//		//if (baseItemData->lefttime_s)
//		//{
//		//}
//	}
//	else if (status == GRID_FREE)
//	{
//		tGridData tgd;
//		tgd.pos = pos;
//		tgd.slot =slot;
//		tgd.url="";
//		tgd.status =status;
//		tgd.src =src;
//		gridItem->updateGrid(tgd);
//
//		gridItem->setIsLock(false);
//		gridItem->setIsBinding(false);
//		gridItem->showNumLabel(false);   //不显示数量label
//		//内颜色框
//		gridItem->showColorRect(false,1);  //不显示
//		//外框
//		gridItem->showColorRect(false,0);   //点击显示
//		gridItem->setColorRectColor(ccc3(255,255,0),0);  //黄色
//	}
//	else if (status == GRID_LOCKED)
//	{
//		tGridData tgd;
//		tgd.pos = pos;
//		tgd.slot =slot;
//		tgd.url="";
//		tgd.status =status;
//		tgd.src =src;
//		gridItem->updateGrid(tgd);
//
//		gridItem->setIsLock(true);
//		gridItem->setIsBinding(false);
//		gridItem->showNumLabel(false);   //不显示数量label
//		//内颜色框
//		gridItem->showColorRect(false,1);  //不显示
//		//外框
//		gridItem->showColorRect(false,0);   //点击显示
//		gridItem->setColorRectColor(ccc3(255,255,0),0);  //黄色
//	}
//}
//
//void updateWXGridByBaseItemData( WXGrid * grid,BaseItemData * baseItemData/*=NULL*/ )
//{
//	if (baseItemData)
//	{
//		updateWXGridByBaseItemData(grid,baseItemData,GRID_USED,0,0,0);
//	}
//	else
//	{
//		updateWXGridByBaseItemData(grid,NULL,GRID_FREE,0,0,0);
//	}
//}
//
//void updateWXGridByBaseItemData( WXGrid * grid,BaseItemData * baseItemData,int status,int pos/*=0*/,int slot/*=0*/,int src/*=0*/ )
//{
//	if (status==GRID_USED)
//	{
//		tGridData tgd;
//		tgd.id  = baseItemData->entry;
//		tgd.pos = pos;
//		tgd.slot = baseItemData->slot;
//		tgd.num = baseItemData->count;
//		CCString* wk_str = CCString::createWithFormat("ui/itemimage/%d.pvr.ccz", baseItemData->displayid);
//		tgd.url = wk_str->getCString();
//		tgd.status =status;
//		tgd.src =src;
//
//		grid->updateGrid(tgd);
//
//		grid->setIsLock(false);
//
//		//物品绑定，小锁
//		if (baseItemData->isbonded)
//		{
//			grid->setIsBinding(true);
//		}
//		else
//		{
//			grid->setIsBinding(false);
//		}
//		//数量label
//		if (baseItemData->count==1 ||baseItemData->count==0)   // 数量为0或者1不显示数量label
//		{
//			grid->showNumLabel(false);
//		}
//		else
//		{
//			grid->showNumLabel(true);
//		}
//
//		//内颜色框
//		grid->showColorRect(true,1);
//
//		switch(baseItemData->qualty)
//		{
//		case 0: 
//			{
//				grid->setColorRectColor(QUALTY_CCC3_0,1);  
//				break;
//			}
//		case 1:
//			{
//				grid->setColorRectColor(QUALTY_CCC3_1,1);  
//				break;
//			}
//		case 2:
//			{
//				grid->setColorRectColor(QUALTY_CCC3_2,1);  
//				break;
//			}
//		case 3:
//			{
//				grid->setColorRectColor(QUALTY_CCC3_3,1);
//				break;
//			}
//		case 4:
//			{
//				grid->setColorRectColor(QUALTY_CCC3_4,1);  
//				break;
//			}
//		case 5:
//			{
//				grid->setColorRectColor(QUALTY_CCC3_5,1);  
//				break;
//			}
//		default:
//			break;
//
//		}
//
//		//外框
//		grid->showColorRect(false,0); //点击显示
//		grid->setColorRectColor(ccc3(255,255,0),0);     //黄色
//	}
//	else if (status == GRID_FREE)
//	{
//		tGridData tgd;
//		tgd.pos = pos;
//		tgd.slot =slot;
//		tgd.url="";
//		tgd.status =status;
//		tgd.src =src;
//		grid->updateGrid(tgd);
//
//		grid->setIsLock(false);
//		grid->setIsBinding(false);
//		grid->showNumLabel(false);   //不显示数量label
//		//内颜色框
//		grid->showColorRect(false,1);  //不显示
//		//外框
//		grid->showColorRect(false,0);   //点击显示
//		grid->setColorRectColor(ccc3(255,255,0),0);  //黄色
//	}
//	else if (status == GRID_LOCKED)
//	{
//		tGridData tgd;
//		tgd.pos = pos;
//		tgd.slot =slot;
//		tgd.url="";
//		tgd.status =status;
//		tgd.src =src;
//		grid->updateGrid(tgd);
//
//		grid->setIsLock(true);
//		grid->setIsBinding(false);
//		grid->showNumLabel(false);   //不显示数量label
//		//内颜色框
//		grid->showColorRect(false,1);  //不显示
//		//外框
//		grid->showColorRect(false,0);   //点击显示
//		grid->setColorRectColor(ccc3(255,255,0),0);  //黄色
//	}
//}
