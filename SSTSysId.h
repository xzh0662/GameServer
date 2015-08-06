#ifndef __SST_SYSTEM_ID_H__
#define __SST_SYSTEM_ID_H__

namespace tdzm
{
	namespace SystemId
	{
//		/*****************************************
//		/*系统ID定义
//		/****************************************/
		enum SystemId
		{
			sysLogin		= 1,//登陆系统
			sysPlayer		= 2,//玩家系统(无实际系统模块)
			sysAbil			= 3,//属性系统
			sysBattle		= 4,//战斗系统
			sysRoom			= 5,//房间系统
			sysEquip		= 6,//装备系统
			sysBag			= 7,//背包系统
			sysQuest		= 8,//任务系统
			sysFriend		= 9,//好友系统
			sysScene		= 10,//场景系统
			sysTalkNpc		= 11,//玩家npc交互系统
			sysChat			= 12,//玩家交谈
			sysWeapon		= 13,//武器系统
			sysTeam			= 14,//组队系统
			sysSkill		= 15,//技能系统
			sysNotable		= 16,//名人系统
			sysDuplicate	= 17,//副本通关系统
			sysBuffer		= 18,//BUFF系统
			sysAcupoint		= 19,//经脉系统
			sysArena		= 20,//竞技场系统
			sysTravel		= 21,//游历系统
			sysExplore      = 22,//古墓探险系统
			sysGuild		= 23,//帮派系统
			sysEnergy		= 24,//体力系统
			sysAward		= 25,//奖励系统
			sysNotify		= 26,//公告系统
			sysMoneyShop    = 27,//钱庄
			sysVip			= 28,//VIP系统
			sysRecharge		= 29,//充值系统
			sysMopUp		= 30,//扫荡
			sysMail			= 31,//邮件
			sysActive		= 32,//活跃度
			sysDailyQuest	= 33,//日常任务
			sysJiangHu		= 34,//江湖闯荡
			sysSpQuest		= 35,//特殊任务
			sysRank			= 36,//排行系统
			sysShop         = 37,//商城系统
			sysSwordGrave	= 38,//剑冢系统
			sysWorldBoss	= 39,//世界BOSS系统
			sysHotel		= 40,//客栈系统
			sysMount        = 41,//坐骑系统
			sysOpenSys      = 42,//系统开放
			sysGoal			= 43,//目标系统
			sysActivity     = 44,//活动系统
			sysExtend		= 45,//扩展玩法系统
			sysRolePart     = 46,//角色部位
			sysLeader       = 47,//武林盟主系统
			sysMoZun		= 48,//魔尊系统
			sysXinFa        = 49,//心法系统
			sysPointsRace	= 50,//问鼎江湖
			sysFasion		= 51,//时装系统
			sysTitle		= 52,//称号系统
			sysCrossUnion	= 53,//跨服战系统
			sysWing         = 54,//神翼系统
			sysIntegralExchange = 55,//积分兑换
			sysSwitchJob		= 56,//转职
			sysChump		= 57,//木人阵
			sysSlave		= 58,	//奴隶系统
			sysMagicWeapon	= 59,	//神兵系统
			sysPet          = 60,	//宠物系统
			sysHuashan		= 61,	//华山系统
			sysTreasureDuplicate = 62,	//武林夺宝系统
			sysEvilDuplicate = 63,	//恶人谷逃杀系统
			sysBeauty		= 64,	//美人系统
			sysSysPreNotice = 65,   //系统功能预告
			sysCount,
		};

//		/**************************************
//		/*帮派系统ID定义
//		/**************************************/
		enum GuildSysId
		{
			gsInfo			= 1,	//帮派基本信息
			gsMember		= 2,	//成员列表
			gsApplicant		= 3,	//待审核列表
			gsSellerInfo	= 4,	//神秘货郎信息
			gsFightField	= 5,	//武斗堂信息
			gsSacrifice		= 6,	//祭祀
			gsGVG           = 7,    //攻城战
			gsCity			= 8,	//帮派争霸
		};

//		/**************************************
//		/*商城系统ID定义
//		/**************************************/
		enum GoodsSysId
		{
			gidGoods			= 1,	//帮派基本信息

		};

		/*****************************************
			*游戏UI ID定义,需跟前端保持一致
		****************************************/
		enum GameUIId
		{
			uiLead		= 0,//角色头像界面
			uiLocked	= 1,//目标界面
			//uiHitCounter= 2,//连击显示界面
			uiRole		= 3,//角色界面
			uiEquip		= 4,//装备界面
			uiBag		= 5,//背包界面
			uiNpcTalk	= 6,//NPC对话界面
			uiNpcTalkTips=7,//NPC对话提示界面
			uiBattleTalk= 8,//战场对话界面
			uiBtn		= 9,//主按钮界面
			uiTrack		= 10,//跟踪界面
			uiChat		= 11,//聊天界面
			uiSkill		= 12,//学习技能界面
			uiAcupoint	= 13,//经脉界面
			uiQuest		= 14,//任务界面
			uiWeapon	= 15,//武器界面
			uiNotableEmploy= 16,//门客界面
			uiTravel	= 17,//游历界面
			uiArena		= 18,//竞技场界面
			uiExplore	= 19,//古墓探险界面
			uiGuildList = 20,//帮派列表界面
			uiGuildTab	= 21,//帮派信息界面
			uiDuplicate	= 22,//副本界面
			uiDupScene	= 23,//副本场景辅助界面
			uiDupGrade	= 24,//副本评分界面
			uiDupPass	= 25,//副本通关界面
			uiSearchTeam= 26,//寻找队伍界面
			uiRevive	= 27,//复活界面
			uiActivity	= 28,//活动界面
			uiAdventure	= 29,//奇遇界面
			uiConfig	= 30,//配置界面
			uiPrompt	= 31,//弹窗提示界面
			uiTips		= 32,//提示界面
			uiAssistant	= 33,//小助手
			uiRoomHall	= 34,//多人副本大厅界面
			uiRoomTeam	= 35,//多人副本房间界面
			uiSysTab	= 36,//系统标签界面
			uiMaid		= 37,//侍女
			uiMount		= 38,//坐骑  (已无用)
			uiNotify	= 39,//公告
			uiMoneyShop	= 40,//钱庄
			uiBeads		= 41,//灵珠界面
			uiWeaponEvolve=42,//武器进阶
			uiJewelCombi= 43,//佩饰合成
			uiVipAwardRecharge=44,//奖励、VIP、充值界面
			uiBeadTower	= 45,//灵珠塔
			uiDupInfo   = 46,//副本信息界面
			uiMopUp		= 47,//扫荡界面
			uiMail		= 48,//邮件界面
			uiEasyTips	= 49,//简易提示界面
			uiJiangHu= 50,//江湖闯荡
			uiFriend = 51,//好友界面
			uiActive	= 52,//活跃度界面
			uiDownload	= 53,//下载微端界面
			uiDailyQuest = 54,//日常任务
			uiExtractGift = 55,//宝箱抽取
			uiRankSummary = 56,//排行榜摘要
			uiQuestTip	= 57,//任务追踪，页游专用
			uiQuestInfoTips = 58,//任务面板的附属面板，显示信息
			uiTrain			= 59,//练功界面
			uiShop      = 60,//商城界面
			uiSwordGrave = 61,//守卫剑冢
			uiExchange = 63,//兑换界面
			uiNotableTab  = 64,//名人标签界面
			uiNotableList = 65,//江湖谱界面
			uiNotableInfo = 66,//名人操作界面
			uiNotableCards = 67,//名人拜帖界面
			uiNotableMatrix= 68,//名人阵法界面
			uiWorldBoss = 69,//世界BOSS界面
			uiWorldBossResult = 70,//世界BOSS结算界面
			uiTravelEncounter = 71,//游历偶遇界面
			uiNotableNew	= 72,//新名人界面
			uiHotel	= 73,//客栈界面
			uiFCMNotify = 74,//防沉迷通知
			uiFCMCheck	= 75,//防沉迷验证
			uiMysticalSeller = 76,//客栈江湖秘郎
			uiMountTab = 77,//坐骑标签界面（坐骑开放使用）
			uiMountInfo = 78,//坐骑信息
			uiMountAdvance = 79,//坐骑进阶
			uiMountStrong = 80,//坐骑强化
			uiMountMateriCombi = 81,//坐骑材料合成
			uiNotableBaldric = 82,//名人配饰
			uiGuildGVGResult = 83,//攻城战排行面板
			uiCharView = 84,	//查询角色信息面板
			uiMountTrain = 85,  //坐骑培养
			uiMountList = 86,   //坐骑列表
			uiGoal = 87,   //目标界面
			uiFirstRecharge = 88,//首充界面
			uiGratiaShop = 89,//特惠商店
			uiGuildJuyi = 90,//聚义厅
			uiGuildWudou = 91,//武斗堂
			uiGuildJisi = 92,//祭祀馆
			uiGuildYishi = 93,//议事馆
			uiBravoActivity = 94,//精彩活动
			uiZhuaChong	= 95,	//抓宠界面
			uiRolePart = 96,//角色部位界面
			uiGuildMonsterFightResult = 97,//帮派神兽战结果
			uiSpecialActivity = 98,//开服精彩活动
			uiDuplicateMap	= 99,//副本地图界面
			uiFanPai		= 100, //翻牌界面
			uiNewTravelMap	= 101,//新游历地图开启界面
			uiLearnSkill	= 102,	//学习技能面板
			uiSkillTalent	= 103,	//技能天赋面板
			uiLeaderMain	= 104,	//武林盟主界面
			uiGuildSeller	= 105,	//帮派商店
			uiGuildTabList	= 106,	//帮派界面帮派列表
			uiGameCorona	= 107,	//登陆抽奖界面
			uiGameFoundation= 108,	//基金计划界面
			uiFireworks		= 109,  //烟花界面
			uiShowTreasure  = 110,  //珍贵展示
			uiSeriesGift	= 111,	//激活码
			uiGuildCity		= 112,	//帮派争霸.
			uiGuildCityGVGResult = 113, //帮派争霸GVG的结果
			uiGuidance		= 114,	//攻略界面
			uiPowerGoal		= 115,	//战力目标界面
			/*** 魔尊界面 ***/
			uiMoZunMain		= 116,	//魔尊界面
			uiMoZunList		= 117,	//魔尊列表
			uiMoZunRank		= 118,	//魔尊排行
			uiMoZunFeatsAward	= 119, //魔尊功勋奖励
			uiMoZunRankAward	= 120, //魔尊排行榜奖励
			uiMoZunFound	= 121,	//发现魔尊
			uiXinFaMain		= 122,	//心法主界面

			uiOnlineAward	= 123,	//在线奖励界面
			uiArenaAward	= 124,	//竞技场奖励界面
			uiTotalLoginAward = 125,	//累计登陆奖励界面
			uiLevelAward	 = 126,	//等级奖励界面
			uiVipAcceseAward = 127,	//VIP奖励界面
			uiGuildCitySelect = 128, //帮派争霸入口选择.

			uiQuestTab		= 129,	//任务主界面
			uiQuestCanAccept = 130,	//可接任务面板
			uiQuestAccept = 131,	//已接任务面板
			uiMoZunKill		= 132, //魔尊击杀界面

			uiRecharge		= 133,	//充值界面
			uiRechargeTab	= 134,	//充值面板主界面

			uiAttriRankPanel	= 135,	//属性战力排行榜

			uiPointsRaceMainPanel	= 136,	//问鼎江湖主界面
			uiPointsRaceResultPanel	= 137,	//问鼎江湖胜利结算面板.

			uiXinFaLvlUp	= 138,  //心法升级界面
			uiXinFaStarUp   = 139,  //心法升阶界面
			uiXinFaChoose   = 140,  //心法选择界面
			uiXinFaExtract  = 141,  //心法抽取结果界面
			uiXinFaView     = 142,  //心法预览界面

			uiHappyLotteryPanel	= 143,	//开心抽奖面板
			uiGameShareAward=144,	//社会化平台分享奖励界面
			uiGameFashion	= 145,//时装面板

			uiDupFanpai		= 146,//副本翻牌页面
			uiInvestActivity	= 147,	//投资面板
			uiDupElitePanel	= 148,	//精英副本
			uiInvestAffirmPanle	= 149,	//投资确认面板
			uiGameTitlePanel = 150, //称号面板
			uiExchangeShop = 151,   //兑换商城
			uiCollectionLottery = 152,	//集物抽奖
			uiTreasureBowl = 153,	//聚宝盆
			uiTreasureBowlResult = 154,	//聚宝盆结果
			uiWeaponMainTab = 155,	//武器主面板
			uiWeaponEffect = 156,	//武器神光界面
			uiWeaponEffectTips = 157,	//武器10次升星界面
			uiHotelHouseMaid = 158,	//客栈挂机
			uiEquipAdvance = 159,   //装备进阶

			/* 无尽之塔界面 */
			uiEndlessTowerHelper = 161,	//无尽之塔帮助
			uiEndlessTowerRank = 162,	//无尽之塔排行榜
			uiEndlessTowerFight = 163,	//无尽之塔战斗
			uiEndlessTowerRankAward = 164,	//无尽之塔排行榜奖励
			uiMergeGratiaShop=165,
			uiEndlessTowerFailure = 166,	//无尽之塔失败
			uiEndlessTowerPass = 167,	//无尽之塔通关
			uiEndesssTowerPassAward = 168,	//无尽之塔通关奖励

			uiMountSkill = 169,  //坐骑技能
			uiMountSkillUpgrade = 170, //坐骑技能升级
			uiEndlessTowerSelectMode = 171,	//无尽之塔选择模式
			uiCrossUnionFight = 172,	//跨服战界面
			uiWorldBossCall	= 173,	//世界BOSS召唤
			uiItemExchange	= 174,	//道具兑换
			uiCrossUnionArenaAward =175,	//跨服竞技场奖励面板
			uiIntegralExchange = 176,	//积分兑换
			uiHelperTips = 177,	//通用帮助界面

			uiWingMain			= 178,	//神翼主界面
			uiWingStrong		= 179,	//神翼强化界面
			uiWingAdvance		= 180,	//神翼进阶
			uiPlumeInfo			= 181,	//彩羽信息

			uiChump				= 182,	//木头人活动
			uiChumpRank			= 183,	//木头人活动排行
			uiChumpFinish		= 184,	//木头人活动挑战结束

			uiSwitchJob			= 185,	//转职
			uiSkillPreview		= 186,	//技能预览
			uiMainCoronaLotteryGold	= 187,	//全民大转转
			uiTreasureTree		= 188,	//奇珍异宝树
			uiTreasureBox		= 189,	//宝箱
			uiVipPM				= 190,	//vip客服
			uiSlave				= 191,	//奴隶界面
			uiMagicWeaponMain	= 192,	//神兵主界面
			uiMagicWeaponInfo	= 193,	//神兵信息界面
			uiMonthLoginAward	= 194,	//神兵签到奖励界面
			uiJiangHuTreasure	= 195,	//江湖宝藏界面
			uiMagicWeaponResult	= 196,	//神兵结果显示
			uiMonthLoginAwardDetail = 197,//神兵签到奖品显示
			uiGoldCard	= 198,	//月卡界面
			uiBeadsEvolve	= 199,	//灵珠进阶界面
			uiOpenActPanel	= 200,	//主界面开服活动二级按钮面板
			uiSelfChar	= 201,	//自己属性界面
			uiSale		= 202,	//出售界面
			uiDecomposition	= 203,	//分解界面
			uiCommonBag	= 204,	//通用小背包
			uiRename	= 205,	//改名界面
			uiPartInlay	= 206,  //部位镶嵌界面
			uiTitleTips = 207,	//称号TIPS
			uiDailyTab	= 208,	//日常主界面
			uiWildMap	= 209,	//野外挂机
			uiWildBuffBuy	= 210,	//购买BUFF
			uiWildGather	= 211,	//野外挂机搜集界面
			uiHuashan		= 212,
			uiHuashanRank	= 213,
			uiHuashanInfo	= 214,
			uiDupTeamList	= 215,	//副本组队列表界面
			uiDupTeamInfo	= 216,	//副本队伍信息界面
			uiHuashanKing	= 218,	//华山论剑霸主界面
			uiPCDupMopUp	= 219,	//网页新版扫荡界面
			uiContinueWarn	= 220,	//继续游戏提示
			uiArenaRank		= 221,	//竞技场排名界面
			uiChargeDiscount		= 222,	//充值返利
			uiChargeDiscountResult	= 223,	//充值返利提示界面
			uiKaifuActivity			= 224,	//开服活动界面
			uiFirstRechargeAgain	= 226,	//再次充值
			uiFirstRechargeSingle	= 227,	//单笔充值
			uiDailyCharge			= 228,	//每日首充
			uiPriviliageAward		= 229,	//360卫士特权
			ui360AccelerateBall		= 230,	//360加速球
			ui360GameCenterLogin	= 231,	//360游戏大厅
			uiActivityAddonRecharge = 232,	//累计充值活动（普通日常活动）
			uiSwitchJobMain			= 233,	//转职主界面
			uiGetBackAward			= 234,	//资源找回界面
			uiActivityDuplicateMain = 235,	//活动副本主界面
			uiActDupFestival		= 236,	//活动副本狂欢活动
			uiActDupChallenge		= 237,	//活动副本挑战教主
			uiFirstRechargeFixed	= 238,  //定额充值
			uiEvilValleyRank		= 239,	//恶人谷排行
			uiEvilValleyKing		= 240,	//恶人谷霸主界面
			uiEvilValleySummary		= 241,	//恶人谷战斗核算面板

			//宠物界面
			uiPetMain				= 242,	//宠物界面
			uiPetFight				= 243,	//宠物出战
			uiPetBag				= 244,	//宠物背包
			uiPetMap				= 245,	//宠物图鉴
			uiPetActive				= 246,	//宠物活动
			uiPetBreeding			= 247,	//宠物繁殖
			uiPetUplevel			= 248,	//宠物吃经验丹
			uiPetInfo				= 249,	//宠物详细信息
			uiPetChoose				= 250,	//选择宠物
			uiPetEat				= 251,	//宠物吞噬
			uiPetIsland				= 252,	//宠物岛
			uiPetSkillPreview		= 253,	//宠物技能预览
			uiPetExtract			= 254, //宠物抽卡
			uiHefuActivity			= 255,	//合服活动界面
			uiMultipleChallenge		= 256,	//多人挑战界面
			ui360PrivComfirmPanel	= 257,	//360特权确定窗口
			uiTempBag				= 258, //临时背包

			//美人系统
			uiBeautyMain			= 259,	//美人系统主界面
			uiBeautyDirectory		= 260,	//美人录
			uiBeautyBead			= 261,	//美人珠
			uiBeautyLoft			= 262,	//美人阁
			uiBeautyBath			= 263,	//美人浴
			uiBeautyTarget			= 264,	//美人目标

			uiGoldEgg               = 265,	//砸金蛋
			uiMountEquip            = 266,	//坐骑装备
			uiMountJuHun            = 267,	//聚魂

			uiBeautyShop            = 268,	//在水一方（美人商店）
			uiMountEquipBag         = 269, //坐骑装备背包
			uiBeautyAdd             = 270,	//获得美人提示
			uiSingleRechangePanel   = 271,	//单笔充值界面

			uiEquipBeadPanel        = 272,	//灵珠装备界面
			uiBeadPackPanel         = 273,	//灵珠背包
			uiBeautyBeadAdvanced    = 274,	//灵珠进阶

			uiSysPreNotifyPanel     = 275,  //功能预告

			uiCount,
		};

			/*****************************************
			*系统功能ID定义
			*带有标签页选择的系统，需要定义每个标签对应的功能id
			****************************************/
		enum GameFunctionId
		{
			/*************************************
			*注意!!添加新的ID需要在后端添加同样的ID
			**************************************/
			funcActor = 0,
			funcWeapon = 1,
			funcEquip = 2,
			funcMountInfo = 3,//坐骑信息
			funcMountTrain = 4,//坐骑培养
			funcMountAdvance = 5,//坐骑进阶
			funcMountStrong = 6,//坐骑强化
			funcMateriCombi = 7,  //材料合成

			funcNotableInfo = 8,//名人信息
			funcNotableList = 9,//江湖谱
			funcNotableCards = 10,//拜帖
			funcNotableMatrix = 11,//阵法
			funcNotableBaldric = 12,//名人佩饰
			funcGoal = 13,//目标

			funcPartHead = 14,//强化头部
			funcPartDress = 15,//身体
			funcPartPants = 16,//腿部
			funcPartBoot = 17,//脚部
			funcPartRing = 18,//戒指
			funcPartEarring = 19,//耳环
			funcPartNecklace = 20,//项链
			funcPartBelt = 21,//腰带

			funcGuildJuyi = 22,//聚义厅
			funcGuildWudou = 23,//武斗堂
			funcGuildJisi = 24,//祭祀馆

			funLearnSkill = 25,
			funSkillTalent = 26,

			funGuidance = 27,
			funPowerGoal = 28,

			funJewelCombin = 29,//合成界面

			funActive = 30,//活跃度
		
			funMountXunchong = 31,//训宠界面

			funQuestAccept = 32,//已接任务
			funQuestCanAccept = 33,//可接任务
			funQuestDaily = 34,//日常任务

			funEquipAdvance = 36,//装备进阶

			funOnlineAward = 40,		//在线奖励
			funLoginAward	= 41,		//累计登陆奖励
			funLevelAward = 42,			//等级奖励
			funArenaAward = 43,			//竞技场奖励
			funVipAcceseAward = 44,		//VIP奖励
			funSeriesAward = 45,		//激活码


			funRecharge = 50,			//精彩充值
			funDailyGratiaShop = 52,	//日常优惠商店
			funLevelGratiaShop = 51,	//等级优惠商店
			funVipGratiaShop = 53,		//VIP优惠商店

			funActivityShop = 54,		//节日特惠商店

			funXinFaExtract = 60,       //心法藏经阁
			funXinFaBag = 61,           //心法背包
			funXinFaFormation = 62,     //心法布阵
			funXinFaDebris = 63,        //心法碎片

			funcMountSkill = 64,        //坐骑技能

			funcHidePlayer = 65,		//隐藏附近玩家，换线
			funcBuyEnergy = 66,			//购买体力
			funcAutoAttack = 67,		//自动攻击

			funcWingMain	= 68,		//神翼主界面
			funcWingStrong  = 69,		//神翼强化
			funcWingAdvance = 70,       //神翼进阶
			funcPlumeInfo   = 71,       //彩羽操作
			funcSwitchJob   = 72,		//转职

			funMagicWeapon = 73,		//神兵
			funMonthLoginAward = 74,	//神兵签到

			funcPartWeapon = 75,		//武器强化
			funcPartInlay = 76,			//装备进阶
			funcPartEmblem = 77,		//徽章强化

			funcVipGratia = 78,			//vip商品
			funcLevelGratia = 79,		//等级商品
			funcActivityGratia = 80,	//特惠商品
			funcDailyGratia = 81,		//活动商品
			funcFashionExchange = 82,	//时装兑换
			funcTitleExchange = 83,		//称号兑换
			funcVacationExchange = 84,	//节日兑换
			funcBaldricExchange = 85,	//佩饰兑换
			funcHonorExchange = 86,		//荣誉兑换

			funcLeadPanelPowerUp = 87,	//角色信息界面战力提升
			funcLeadPanelBuyEnergy = 88,//角色信息界面购买体力
			funcLeadPanelVip = 89,		//角色信息界面vip
			funcLeadPanelRecharge = 90,	//角色信息界面充值
			funcGetBackAward = 91,		//资源找回界面

			funMountEquip = 92,		//坐骑装备

			/*************************************
			*注意!!添加新的ID需要在后端添加同样的ID
			**************************************/
			funCount,
		};
	}
}

#endif
