#ifndef __SSTUAN_NET_COMMAND_H__
#define __SSTUAN_NET_COMMAND_H__

namespace tdzm
{
	namespace NetCmd
	{
//		/******************************************************
//		/* 登陆系统命令码
//		/*****************************************************/
		enum LoginCmd
		{
			cRequestLogin	= 1,//请求登陆(string account, string password)
			cQueryCharList	= 2,//查询角色列表
			cCreateChar		= 3,//创建新角色(string charName, byte gender)
			cDeleteChar		= 4,//删除角色(PlayerId charId)
			cEnterGame		= 5,//请求进入游戏(PlayerId charId, string charName)
			cGetCharName    = 6,//请求随机角色名

			sLoginRet		= 1,//返回登陆请求(int errorCode(0表示登陆成功), int AccountId)
			sSendCharList	= 2,//返回角色列表
			sCreateCharRet	= 3,//创建角色返回(int errorCode(0表示成功), stream charDesc)
			sDeleteCharRet	= 4,//返回删除角色(int errorCode(0表示成功))
			sEnterGameRet	= 5,//返回进入游戏请求(int errorCode(0表示成功))
			sGetCharNameRet = 6,//返回随机角色名
			sReadyForRun	= 7,//所有客户端关心的数据发送完毕，玩家进入游戏状态
		};

//		/******************************************************
//		/* 属性系统命令码
//		/*****************************************************/
		enum AbilCmd
		{
			sSendAbility	= 1,//发送角色属性数据(ActorAbilData abil)
			sExpChange		= 2,//经验值改变(int exp, int expMax)
			sHPMPChange		= 3,//角色体力和内力变更(int hp, int mp)
		};

//		/******************************************************
//		/* 装备系统命令码
//		/*****************************************************/
		enum EquipCmd
		{
			cTakeOnItem		= 1,//请求穿上装备(ItemSeries series)
			cTakeOffItem	= 2,//请求脱下装备(ItemSeries series)
			cInlayJewel     = 3,//请求镶嵌宝石
			cStrengthenEquip = 4,//请求强化装备
			cTakeOffJewel    = 5,//请求取下宝石
			cCleanCD         = 6,//请求清除CD
			cOpenInlayHole   = 7,//请求开放镶嵌孔
			cReqItemDecompose = 8,//请求物品分解
			cStrengthenPart  = 9,//请求部位强化
			cReqEquipAdvance = 10,//请求装备进阶

			sSendEquipItems	= 1,		//发送装备物品列表(int count, array of (byte pos, struct SendClientItem))
			sSetEquipItem	= 2,		//设置特定位置装备物品(byte pos, struct SendClientItem(不存在此数据表示移除装备))
			//sUpdateEquipItemCount = 3,//设置特定装备物品的数量(ItemSeries series, int newCount)
			sSendInlayResult = 3,		//发送镶嵌结果返回
			sSendStrengthenResult = 4,	//发送强化结果返回
			sSendTakeOffJewelRes = 5,	//发送取下宝石结果
			sSendCleanCDRes      = 6,	//发送清除CD结果
			sSendOpenHoleRes     = 7,	//发送开孔结果
			sSendJewelList = 8,			//发送佩饰物品列表
			sRetItemDecompose = 9,		//物品分解返回
			sStrengPartRes  = 10,		//发送部位强化结果
			sMasterInfoChange  = 11,	//盟主&城主信息变更
			sRetEquipAdvance = 12,		//返回装备进阶结果
		};

//		/******************************************************
//		/* 背包系统命令码
//		/*****************************************************/
		enum BagCmd
		{
			cOpenBagGrid    = 1,//请求开启背包格子
			cSellItem       = 2,//请求出售物品
			cReqJewelCombi  = 3,//请求佩饰合成
			cUseItem        = 4,//使用物品
			cExtractItem    = 5,//抽取物品
			cOpenGoldExt    = 6,//开启元宝抽取
			cAskBagItemsInfo= 7,//获取背包数据
			cSendTidyData   = 8,//向server发送物品整理数据
			cAskOpenTreasureBox = 9,	//请求开启宝箱 (int boxId, int openCount)
			cReqUnlockGrid  = 10,//请求已开锁数据
			cReqTempBagInfo = 11,//请求临时背包数据
			cReqGetItemFormTempBag = 12,//从临时提取物品
			cReqTidyTempBag = 13,//请求整理临时背包

			sSendBagItems	= 1,//发送背包物品列表(int count, array of struct SendClientItem)
			sAddBagItem		= 2,//添加物品到背包(struct SendClientItem)
			sDelBagItem		= 3,//从背包删除物品(ItemSeries series)
			sUpdateBagItem	= 4,//更新背包中某个物品数据(ItemSeries series, struct SendClientItem)
			sUpdateBagItemCount = 5,//更新背包中某个物品的数量(ItemSeries series, int newCount)
			sCoinChange		= 6,//银两数量改变
			sGameGoldChange	= 7,//元宝数量改变
			sSendOpenBagGrid    = 8,//发送开启背包格反馈
			sSellItemResult = 9,//发送出售结果
			sSendJewelCombiRes  = 10,//发送佩饰合成结果
			sUseItemRes     = 11,//发送使用物品结果
			sExtractItemRes = 12,//发送抽取物品结果
			sOpenGoldExtRes = 13,//发送开启元宝抽取结果
			sRetTidyBag     = 14,//整理背包
			sGainItem		= 15,//获取道具
			sRepOpenTreasureBox = 16,	//宝箱开启返回 (int ret, int nCount, array[int type, int idx, int count] )
			sSendUnlockGrid	= 17,//发送解锁格子信息
			sSendTempBagInfo = 18,//临时背包数据返回
			sRetGetItemFormTempBag = 19,//从临时提取物品返回
			sRemoveTempBagItem = 20,//临时背包移除物品
			sAddTempbagItem = 21,//临时背包增加物品
			sUpdateTempbagItem = 22,//更新临时背包数据

			sSendTemp
		};

//		/******************************************************
//		/* 战斗系统命令码
//		/*****************************************************/
		enum BattleCmd
		{
			cStartRun			= 1,//起跑(int myX, int myY, short speedX, short speedY, short 助跑时间, uint 客户端时间)
			cStopRun			= 2,//停跑(int myX, int myY, uint 客户端时间)
			cNormalAttack		= 3,//普通攻击(char 方向(0左，1右),char actionId)
			cEnterGate			= 4,//进入传送门(int 传送门ID)
			cPickDropItem		= 5,//拾取掉落物品(int ident, TDZMID series)
			cCompleteBattleTalk	= 6,//完成战场对话步骤(short 步骤)
			cImpactSensor		= 7,//触发探测器(short 探测器ID, uint 客户端时间)
			cSceneReady			= 8,//客户端完成场景初始化
			cSkillAttack		= 9,//客户端进行技能攻击(char dir, char 招式索引, ushort 技能ID)
			cLocalActorDead		= 10,//本地对象死亡<机器人,本地怪物>(MonType,MonActorId,PosX,PosY,击杀者ActorId)
			cLocalPlayerHpNotify= 11,//本地玩家血量MP更新(hp,mp)
			cReturnToTown       = 12,//回到主城(将玩家传送会出生点)
			cSwitchLine			= 13,//换线(int 从1开始的线索引)
			cFightInvite		= 14,//邀请挑战(string 角色名称)
			cAcceptFightInvite	= 15,//接受挑战(string 角色名称)
			cReqCharViewInfoByCharId	= 16,//请求查看玩家信息(根据玩家ID)
			cReqCharViewInfoByCharName	= 17,//请求查看玩家信息(根据玩家名称)
			cCharDeviceInfo				= 18,//上传玩家设备信息
			cLocalPlayerSkillContrlAct	= 19,//本地玩家技能控制变化
			cLocalPlayerCheckResult		= 20,//
			cTeleportToScene			= 21,//传送至场景

			sSwitchScene		= 1,//发送初始场景数据
			sActorAppear		= 2,//角色出现
			sActorDisappear		= 3,//角色消失
			sSendMySelf			= 5,//发送自己的角色描述
			sStartRun			= 6,//角色起跑
			sStopRun			= 7,//角色停跑
			sSetPosition		= 8,//设置角色位置
			sNormalAttack		= 9,//玩家进行普通攻击
			sServerTime			= 10,//发送服务器时间
			sNpcQuestState		= 11,//NPC的任务状态(INT_PTR npcId, char state)
			sStruck				= 12,//角色受击(PlayerId actorId, int hp, int hpMax)
			sDie				= 13,//角色死亡(PlayerId actorId, int 死亡倒地后X, int 死亡倒地后Y)
			sReviviscent		= 14,//角色复活(PlayerId actorId)
			sLevelChange		= 15,//角色升级(PlayerId actorId, ushort level, ActorAbilData abil)
			sActorDescChange	= 16,//角色描述改变(PlayerId actorId, ActorDesc desc)
			sItemDrop			= 17,//物品掉落(PlayerId dropActorId, byte count, array of SendClientDropItem)
			sPlayerDropItem		= 18,//掉落物品消失(TDZMID series)
			sShowBattleTalk		= 19,//呈现战场对话(int battleId, short step)
			sOpenGate			= 20,//开启传送门(short gateId);
			sBattleGoTip		= 21,//战场内提示移动方向(int x, int y)
			sMoveTo				= 22,//使角色移动到特定位置(short 场景ID, int x, int y, uint 移动时间(毫秒))
			sPutSensor			= 23,//放置探测器(short 探测器ID, short 场景ID, int x, int y, short width, short height)
			sDelSensor			= 24,//删除探测器(short 探测器ID， short 场景ID)
			sChangeLayerColor	= 25,//场景层改色(char 层索引, uint argb, uint time)
			sCollapse			= 26,//角色倒地(PlayerId actorId, ushort 倒地时间, ushort 受击保护时间, int 倒地后坐标X, int 倒地后坐标Y)
			sBeatBack			= 27,//角色被击退(PlayerId actorId, int 目的地x, int 目的地y, ushort 退却时间)
			sSkillAttack		= 28,//角色进行技能攻击(PlayerId actorId, char dir, ushort 技能ID, char 招式索引, char 招式等级)
			sLockScene			= 29,//锁屏(short 场景ID, int x, int y, int width, int height)
			sSkillCDSwitcher	= 30,//技能CD开关(bool disabled)
			sHitCountOutTime	= 31,//连击计数清零
			sLocalControlEnable	= 32,//改变本地玩家控制状态（bool 是否允许控制）
			sPlayAction			= 33,//播放角色动作(PlayerId actorId, string 动作名称, int 动作毫秒时间)
			sActorSay			= 34,//角色说话，用于剧情辅助，不在聊天面板显示(PlayerId actorId, string GRT格式内容)
			sMapViewMove		= 35,//镜头移动(x y, 移动时间)
			sShowNpcTalk		= 36,//呈现NPC对话(对象逻辑ID,命令逻辑ID,NPC名称,NPC图像编号,说话内容<GRT格式内容>)
			sShowCharTalk		= 37,//呈现玩家对话(对象逻辑ID,命令逻辑ID,说话内容<GRT格式内容>)
			sShowActorEntryBaTi	= 38,//对象进入霸体(对象entryid,霸体时间,受击保护时间)
			sShowSceneKill		= 39,//场景杀怪数(当前已击杀数,当前总需击杀数)
			sActorAreaChange	= 40,//对象场景区域改变
			sChangeSceneFullColor=41,//场景整体改色(uint argb, uint time)
			sClientUiText		= 42,//UI文本(文本ID,是否时间文本,文本内容,位置X,位置Y,格式结构)
			sChangeMuse         = 43,//改变播放音乐
			sClientProcedure	= 44,//前端调用战场逻辑(副本ID)
			sChangeBattleValue  = 45,//改变战场数值
			sChangeTimeScale	= 46,//改变镜头速度
			sSkillLockTargetMove= 47,//技能效果锁定目标移动(x,y,time)
			sSceneUiEffectAnim	= 48,//场景界面特效(文件名,Y,TIME)
			sActorScale			= 49,//怪物缩放(怪物ID,缩放值)
			sLineChanged		= 50,//线索引改变(int 从1开始的线索引)
			sEnterInvicibility	= 51,//进入无敌状态(int 持续毫秒时间)
			sFightInvite		= 52,//挑战邀请(string 角色名称, int 战胜数 int 失败数)
			sFightInviteFail	= 53,//挑战邀请或应带错误(int 错误码)
			sEnterStoryMode		= 54,//进入剧情模式
			sTotalDeadFailedTime= 55,//全体阵亡失败倒计时
			sActorMapBlock		= 56,//怪物阻挡区域数据下发设置
			sRepCharViewInfo	= 57,//返回查看玩家的详细信息
			sFloatFly			= 58,//角色被击飞(int x, int y, short uptime, short height, short move)
			sTopHpShow			= 59,//头顶血条显示(TDZMID,short width, short height, short TopHeight)
			sActiveDupBlockTime	= 60,//活动副本进入时间限定
			sRepCharViewFail	= 61,//查看信息错误(int 错误码)
			sReqCharDeviceInfo	= 62,//查询玩家设备信息
			sBattleFlagsChange	= 63,//战场标示改变
			sActorShapeChange	= 64,//对象变身
			sActorChangeCamp	= 65,//对象改变阵营
			sBattleMonArrowPoint= 66,//战场怪物箭头
			sBattleAITimeRate	= 67,//挂机战斗频率
			sActorLocalShape	= 68,//对象本地变身
			sActorTriggerSkillContro = 69,//对象触发技能控制
			sCancelSuperBody = 70,		//取消霸体状态
			sBattlePetFightFlag = 71,	//禁止宠物出战
		};

//		/*******************************************************
//		/* 任务系统命令码
//		/*******************************************************/
		enum QuestCmd
		{
			cSendQuestAbort			= 1,	//放弃任务(unsigned short questID)
			cReqQuestDone			= 2,	//请求完成任务(新手指导类型)
			cAskQuestInfo			= 3,	//重新请求任务数据
			cReqQuestAccept			= 4,	//请求接收任务
			cReqQuestSubmit			= 5,	//请求提交任务

			sSendQuestDatas			= 1,	//已接与可接任务列表(int count, array of questID, int count, array of AcceptedData)
			sSendAddCanAcceptID		= 2,	//新增可接任务ID(unsigned short QuestID)
			sSendAddAcceptQuest		= 3,	//新增已接任务(struct SendQuestData)
			sSendDelCanAcceptID		= 4,	//删除可接任务ID(unsigned short QuestID)
			sSendDelAcceptQuest		= 5,	//删除已接任务(unsigned short QuestID)
			sSendAbortQuest			= 6,	//放弃任务(
			sSendUpdateAcceptQuest	= 7,	//更新任务状态(unsigned short questID, unsigned char idx, unsigned char nCount)
			sSendQuestAwardInfo		= 8,	//任务奖励信息
			sSendQuestUpdateNpcTalk	= 9,	//发送任务更新NPC聊天(int npcid)
			sSendStrongerNotify		= 10,	//变强面板项目的后端次数统计(int count， array of pair (strongerItemId, iNum))
			sLastMainQuestChange	= 11,	//最后接主线任务发生变化(int iQuestId)
		};

//		/*******************************************************
//		/* 特殊任务命令码
//		/*******************************************************/
		enum SpQuestCmd
		{
			cGetDownloadAwardResult	= 1,//领取下载微端奖励结果

			sDownloadAwardStatus	= 1,//下载微端任务状态
			sGetDownloadAward		= 2,//领取下载微端奖励
		};

//		/******************************************************
//		/* 玩家与npc交互系统命令码
//		/*****************************************************/
		enum NpcTalkCmd
		{
			sNPCTalkContent	= 1,//发送NPC对话内容
			sNPCTalkClose	= 2,//发送关闭NPC对话框

			cTalkNPC		= 1,//与NPC对话
		};

//		/**********************************
//		/*组队系统命令码
//		/**********************************/
		enum PlayerTeamCmd
		{
			cCreatTeam			=	1,	//请求创建队伍(int sceneId, char 难度)
			cSearchTeam			=	2,	//搜索队伍(int sceneId, char 难度)
			cJoinTem			=	3,	//加入队伍(int sceneId, char难度, unsigned short index)
			cTeamInvite			=	4,	//邀请加入队伍(llid:)
			cQuitTeam			=	5,	//退出队伍
			cTeamKick			=	6,	//踢出队伍(llid:踢出对象ID)
			cTeamInviteReply	=	7,	//邀请队伍的应答
			cReqTeamDamageRank	=	8,	//请求队伍伤害数据

			sSendCreateTeam		=	1,	//创建队伍反馈(char result)
			sSendTeamList		=	2,	//返回搜索界面的队伍列表
			sSendTeamInfo		=	3,	//发送队友信息给自己
			sSendTeamInvite		=	4,	//组队邀请信息
			sSendTeamQuit		=	5,	//退出队伍(llid:退出玩家的ID, flag:退出原因,0主动退出1踢出2解散队伍)
			sSendSelfInfo		=	6,	//发送自己信息给队友
			sSendRetTeamInvite	=	7,	//发送邀请队友反馈信息
			sRepTeamDamageRank	=	8,	//返回队伍伤害数据
		};

//		/******************************************************
//		/* 武器系统命令码
//		/*****************************************************/
		enum WeaponCmd
		{
			sWeaponInfo		= 1,//武器信息
			sAddBead		= 2,//增加灵珠
			sDelBead		= 3,//删除灵珠
			sWeaponFullInfo	= 4,//武器全信息，包括灵珠列表
			sBeadEat		= 5,//灵珠吞噬
			sWeaponOpRes	= 6,//操作响应
			sHoleStatus     = 7,//武器孔状态
			sEternalChange  = 8,//武魂值变更
			sEquipBeadChange= 9,//装备灵珠变更
			sUpgradeCDChange= 10,//强化CD变更
			sAddBeadList	= 11,//增加一组灵珠
			sSearchTower	= 12,//灵珠塔领悟返回
			sBeadTowerInfo	= 13,//灵珠塔信息
			sSoulCount      = 14,//发送神魂值
			sLockBeadList	= 15,//锁定的灵珠列表
			sBeadLockChange	= 16,//灵珠锁定状态改变
			sWeaponEffectChange	= 17,//武器神光数据改变
			sWeaponEffectResult = 18,//武器神光升星结果返回
			sBeadEvolveResult	= 20,//灵珠进阶结果返回
			sBeadEvolveInfo		= 21,//灵珠进阶后信息
			sWeaponEffectTakeOn = 22,//穿戴神光外形返回

			cUpgradeWeapon	= 1,//升级武器
			cActiveWeaponHole=2,//开启武器孔
			cEquipBead		= 3,//装备灵珠
			cUnEquipBead	= 4,//卸下灵珠
			cBeadEat		= 5,//灵珠吞噬
			cEvolveWeapon   = 6,//武器进阶
			cClearCD		= 7,//清除强化CD
			cSearchTower	= 8,//灵珠塔领悟
			cCollectBeads	= 9,//回收灵珠
			cBeadTowerInfo	= 10,//请求灵珠塔信息
			cWeaponInfo		= 11,//请求武器数据
			cBeadLockChange	= 16,//请求更改灵珠锁定状态
			cWeaponEffectUpgrade = 17,	//神光升阶
			cWeaponEffectEnhance = 18,	//神光升星
			cWeaponEffectEnhanceDs = 19,//连续升星 (dal segno)
			cBeadEvolve = 20,//请求灵珠进阶
			cWeaponEffectTakeOn = 21,//请求穿戴神光外形
		};

//		/******************************************************
//		/* 名人系统通讯协议类型
//		/*****************************************************/
		enum NotableCmd
		{
			sNotableListInfo	= 1,//名人列表信息
			sNotableTrain		= 2,//名人培养
			sNotableEmploy		= 3,//名人雇佣变更
			sNotableExpPass		= 4,//名人传功
			sNotableVeinsInfo	= 5,//经脉信息
			sNotableInfo		= 6,//单个名人信息
			sTabletCount		= 7,//洗髓丹数量
			sNotableCardsList	= 8,//名人拜帖列表
			sNotableCardInfo	= 9,//单个名人拜帖信息
			sNotableCardCall	= 10,//拜帖引荐
			sNotableCardVisit	= 11,//拜帖拜访
			sNotableCardExchange= 12,//拜帖兑换洗髓丹
			sNotableOnJewel		= 14,//穿戴佩饰返回
			sNotableOffJewel	= 15,//脱掉佩饰返回
			sNotableJewelOpen	= 16,//名人佩饰开孔返回
			sNotableJewelError	= 17,//名人佩饰错误码
			sNotableMatrixLvlUp	= 18,//名人阵法升级
			sNotableEvolve		= 19,//名人进阶
			sNotableCardSell	= 20,//名人卡出售
			sNotableBuyPoints	= 21,//行动力购买返回
			sNotableAbil		= 22,//门客属性数据
			sNotableTakeOff		= 23,//门客下阵通知
			sNotableOneKeyCardCallInfo = 24,//一键引荐返回
			sNotablePositionData= 25,//位置信息

			cNotableListInfo	= 1,//请求名人列表信息
			cNotableTrain		= 2,//名人培养
			cNotableEmploy		= 3,//雇佣名人为门客
			cNotableExpPass		= 4,//名人传功
			cNotableVeinsStren	= 5,//经脉洗髓
			cNotableVeinsLock	= 6,//锁定经脉
			cNotableVeinsOpen	= 7,//打通经脉
			cNotableCardList	= 8,//请求名人拜帖列表
			cNotableCardCall	= 9,//拜帖引荐
			cNotableCardVisit	= 10,//拜帖拜访
			cNotableCardExchange= 11,//拜帖兑换洗髓丹
			cNotableOnJewel		= 14,//请求穿戴佩饰
			cNotableOffJewel	= 15,//请求脱掉佩饰
			cNotableJewelOpen	= 16,//名人佩饰开孔
			cNotableMatrixLvlUp	= 18,//请求名人阵法升级
			cNotableEvolve		= 19,//名人进阶
			cNotableCardSell	= 20,//名人卡出售
			cNotableTakeOff = 21,//名人下阵
			cNotableOneKeyCardCall = 22,//一键引荐
		};

//		/******************************************************
//		/* 游历系统通讯协议类型
//		/*****************************************************/
		enum TravelCmd
		{
			sTravelInfo			= 1,//游历信息
			sNormalTravel		= 2,//普通游历
			sOneKeyTravel		= 3,//一键游历
			sChallenge			= 4,//点击挑战结果
			sGetAward			= 5,//点击领受结果
			sTravelPoints		= 6,//行动力值通知
			sOneKeyAward		= 7,//一键领取奖励
			sTravelChapterChange= 8,//章节改变
			sTravelNewChapter	= 9,//新章节通知

			cTravelInfo			= 1,//申请游历信息
			cNormalTravel		= 2,//开始普通游历
			cOneKeyTravel		= 3,//开始一键游历
			cChallenge			= 4,//挑战名人
			cGetAward			= 5,//领受奖励
			cBuyTravelPoints	= 6,//购买行动力
			cOneKeyAward		= 7,//一键领取奖励
			cChangeChapter		= 8,//改变游历章节
		};

//		/******************************************************
//		/* 技能系统命令码
//		/*****************************************************/
		enum SkillCmd
		{
			sSkillInfo		= 1,//技能信息
			sEquipSkillChange=2,//装备技能变更
			sAwakeValueChange=3,//参悟值变更
			sLearnSkill		= 4,//学习技能
			sAwakeLevelUp	= 5,//参悟升级
			sSkillOpRes		= 6,//技能操作响应
			sEquipSkillInfo = 7,//装备技能信息
			sLearnPosture	= 8,//学习招式
			sCombineBook	= 9,//合成技能书
			sLearnEnergyChange = 10,//修为值改变
			sTalentInfo		= 11,//天赋信息
			sTalentUpgrade	= 12,//天赋升级
			sMountSkillChange= 13,//装备的坐骑技能变更

			cUpgradeSkill	= 1,//升级技能
			cEquipSkill		= 2,//装备技能
			cUnEquipSkill	= 3,//卸下技能
			cAwakeSkill		= 4,//参悟技能
			cLearnSkill		= 5,//学习技能
			cEquipSkills    = 6,//装备技能 全改变
			cLearnPosture	= 7,//学习招式
			cCombineBook	= 8,//合成技能书
			cSkillInfo		= 9,//请求技能信息
			cTalentInfo		= 10,//请求天赋系想你
			cTalentUpgrade	= 11,//天赋升级
			cBattleLearnSkill = 12,//副本中学习技能
			cSkillCDInfo = 13,//向后端发技能CD数据
		};

//		/****************************************************
//		/*副本通关系统
//		/****************************************************/
		enum duplicateCmd
		{
			cDuplicatePassInfo		= 1,	//请求副本分组的通关情况
			cDupBegin				= 2,	//开始副本
			cDupChoose				= 3,	//选择奖励
			cDupQuit				= 4,	//退出副本
			cDupOnceMore			= 5,	//再次挑战
			cDuplicateRevive		= 6,	//复活
			cDuplicateGradeDone		= 7,	//通关界面操作完成
			cClientBattleWin		= 8,	//前端单人副本通关 前端本地战场逻辑控制
			cClientBattleOpenGate	= 9,	//前端打开传送门 前端本地战场逻辑控制
			cDupInstanceTowerReq	= 10,	//进入灵珠塔
			cDupRequestTowerInfo	= 11,	//请求灵珠塔数据
			cClientBattleStage		= 12,	//副本进度
			cBuyDupGroupTimes		= 13,	//购买关卡组次数
			cGetDupFirstAward		= 14,	//领取副本首通礼包
			cGetDupGroupAward		= 15,	//领取副本组奖励礼包
			cReqDupFanPaiReady		= 16,	//请求翻牌数据
			cReqDupFanPaiDone		= 17,	//请求翻牌数据
			cReqDupFanpaiClick		= 18,	//请求翻牌点击
			cReqDupEliteRecord		= 19,	//请求精英副本记录
			cReqDupAddTimePay		= 20,	//加时付款
			cReqDupEndlessTowerRank	= 21,	//请求无尽之塔排行信息
			cReqEndlessTowerRankAward= 22,	//无尽之塔周排行奖励
			cReqEndlessTowerNextFloor= 23,	//无尽之塔下一关
			cReqEndlessTowerQuickPass= 24,	//无尽之塔快速通关
			cReqEndlessTowerDicePass = 25,	//无尽之塔随机通关
			cReqEndlessTowerDiceResult = 26,	//无尽之塔摇色子处理结果
			cClientBattleStageAward = 27,	//副本进度阶段奖励
			cReqEnterWildMap		= 28,	//请求进入野外挂机场景
			cReqBuyWildHPBuff		= 29,	//请求购买野外挂机BUFF

			sRetDuplicatePassInfo	= 1,	//返回副本的通关情况
			sRetBeginDupInfo		= 2,	//进入副本的反馈信息
			sSendDupInfoUpdate		= 3,	//更新副本开通情况
			sSendDupPassGrade		= 4,	//副本通关评分信息
			sRetDupChooseAward		= 5,	//副本奖励选择返回
			sDupChooseReply			= 6,	//副本奖励选择反馈,-1银两不足
			sDuplicateOpenGate		= 7,	//用于副本通关之后断线重连回来的开门
			sDuplicateShowRevive	= 8,	//显示复活界面
			sDupInstanceTowerRep	= 9,	//返回当前灵珠塔数据
			sRoomInvite				= 10,	//房间邀请
			sDuplicateFail			= 11,	//副本失败
			sDuplicatePassCode		= 12,	//副本通关码
			sDupDayTimesInfo		= 20,	//副本每日通关次数
			sDupUpdateDayTimes		= 21,	//更新副本每日通关数据
			sDupStageAward			= 22,	//副本阶段奖励数据下发
			sDupGroupAllLimitInfo	= 23,	//所有关卡组限制信息
			sDupGroupLimitInfo		= 24,	//单个关卡组限制信息
			sDupGroupAllAwardInfo	= 25,   //所有关卡组领奖信息
			sDupGroupAwardInfo		= 26,   //单个关卡组领奖信息
			sDupGroupGetAward		= 27,	//领取奖励返回
			sDupEndlessTowerPassGrade = 28,	//无尽之塔副本通关评分信息
			sDupStageTempAward		= 29,	//副本特殊奖励下发
			sDupDieFightPowerShowAdvise = 30,	//副本有死亡,退出副本后的战力建议显示

			sDupFanpaiAwards		= 32,	//翻牌奖励数据
			sDupFanpaiClickRet		= 33,	//点击成功返回
			sDupFanpaiUIShow		= 34,	//显示翻牌界面

			sDupEliteRecord			= 40,	//请求精英副本记录
			sDupRepAddTimePay		= 41,	//加时付费返回

			sDupEndlessTowerAll		= 42,	//无尽之塔所有数据
			sDupEndlessTowerInfoBase= 43,	//无尽之塔基础数据
			sDupEndlessTowerUpdate	= 44,	//更新无尽之塔数据
			sDupEndlessTowerRank	= 45,	//无尽之塔排行数据
			sDupEndlessTowerPass	= 46,	//无尽之塔通关
			sDupEndlessTowerRankAward= 47,	//无尽之塔排行奖励
			sDupEndlessTowerQuickPass= 48,	//无尽之塔快速闯塔
			sDupEndlessTowerDicePass = 49,	//随机通关

			sDupUpdateWildHPBuff	= 50,	//更新野外挂机BUFF
			sDupWildRetCode			= 51,	//野外挂机返回码
			sDupWildDupMode			= 52,	//野外挂机场景模式
			sDupWildKillMon			= 53,	//击杀野外怪物
			sDupGatherDropItem		= 54,	//拾取物品
			sDupMaskTitleNotify		= 55,	//副本隐藏称号消息

			sSendCloseUI			= 60,	//通知客户端关闭界面
		
		};

//		/****************************************************
//		/*BUFF系统
//		/****************************************************/
		enum	BuffCmd
		{
			sBuffInfoList			= 1,	//BUFF 列表 信息
			sBuffDelete				= 3,	//BUFF 删除
			sBuffUpdate				= 5,	//BUFF 更新
			sBuffEffect				= 6,	//BUFF 效果
			sBuffHpChange			= 9,	//反弹伤害
			sBuffCast				= 10,	//触发BUFF
			sActorCastBuff			= 11,	//施加者触发BUFF
		};

//		/****************************************************
//		/*经脉系统
//		/****************************************************/
		enum	AcupointCmd
		{
			sAcupointError			=1,
			sAcupointList			=2,
			sAcupointUpdate			=3,
			sEnergyDrugChange		=4,
			sAcupointFightNotice	=5,//冲穴/周天 提示信息
			sAcupointOpenNew		=6,//通知新开经脉

			cAcupointOpen			=1,
			cAcupointChongXue		=2,//冲穴事件
			cAcupointInfo			=3,//前端请求数据
			
		};

//		/**********************************
//		/*竞技场系统
//		/**********************************/
		enum ArenaCmd
		{
			cArenaDataRequest				=	1,	//请求竞技场数据
			cArenaRequestFight				=	2,	//发起挑战
			cArenaRequestAddFightTimes		=	3,	//请求增加挑战次数
			cArenaRequestColdDownFightTime	=	4,	//请求冷却挑战时间
			cArenaGetAward					=	5,	//请求每日奖励奖品
			
			cArenaRobotAttack				=	10,	//机器人发起攻击
			cRobotStartRun		= 20,//机器人起跑
			cRobotStopRun		= 21,//机器人停跑
			cRobotNormalAttack	= 22,//机器人普通攻击
			cRobotSkillAttack	= 23,//机器人技能攻击


			sArenaData						=	1,	//排名,今日可挑战次数,增加挑战元宝量,冷却时间,冷却元宝量,昨日排名奖励,挑战历史记录,
			sArenaTargetRoleData			=	2,	//可挑战对象数据 (数量	struct	{名称,等级,性别,职业,战斗力})
			sArenaFightHistory				=	3,	//增加挑战历史 (时间,主动/被动,挑战者,胜/败,挑战后排名)
			sArenaFightData					=	4,	//更新玩家挑战信息:(排名,今日可挑战次数,增加挑战元宝量,冷却时间,冷却元宝量)
			sArenaFightBegin				=	5,	//挑战开始
			sArenaNotifyAward				=	6,	//通知有奖励可以领取
			sArenaNotEnoughFightTime		=	7,	//剩余挑战次数不足
			sArenaNotEnoughGameGold			=	8,	//元宝不足
			sArenaTargetSkill				=	9,	//挑战对象的技能数据
			sArenaFightFinish				=	10,	//挑战结束
			sArenaTargetRobotData			=	11,	//竞技场机器人数据(RobotData)
			sArenaFightAwardData			=	12,	//竞技场挑战奖励数据
			sChallengeFightStart			=   13, //双人挑战开始
			sChallengeFightResult			=   14, //双人挑战结果(bool 是否胜利)
			sArenaAwardFlag					=	15,	//是否可领奖标记
			sArenaTotalWinTimes				=	16,	//更新胜利次数
			sArenaOutofBuyTime				=	17,	//超出购买次数
			sArenaRecordReward              =	18,	//竞技场排名奖励
			sArenaAffordToBuy				=   19,	//竞技场购买挑战次数成功
		};

//		/******************************************************
//		/* 古墓探险系统通讯协议类型
//		/*****************************************************/
		enum ExploreCmd
		{
			sExploreInfo		= 1,//探险信息
			sNodeEventUpdate	= 2,//节点事件更新
			sExploreResult      = 3,//探险结果
			sDailyReward		= 4,//每日探险收获返回
			sExploreBagInfo     = 5,//探险背包数据返回
			sGainRewardRes      = 6,//从仓库提取物品返回
			sRemoveStorageItem  = 7,//仓库移除物品
			sAddStorageItem     = 8,//仓库增加物品

			cExploreGo			= 1,//开始探险
			cReqDailyReward		= 2,//请求探险收获
			cReqExploreInfo		= 3,//请求最新探险信息
			cReqExploreBag      = 4,//请求探险背包数据
			cGainRewardFromStorage = 5,//从仓库提取物品
		};

//		/*****************************************
//		/*帮派系统
//		/*****************************************/
		enum GuildCmd
		{
			cGuildRequestInfoList				=	1,	//请求帮派列表(short index)
			cGuildCreate						=	2,	//创建帮派(帮派名)
			cGuildApply							=	3,	//申请入帮(帮派唯一ID)
			cGuildApplicant						=	4,	//审核(PlayerId id, 1同意 0拒绝)
			cGuildGiveJob						=	5,	//任职(玩家唯一ID,职务)
			cGuildKick							=	6,	//踢人(玩家唯一ID)
			cGuildModifyNotify					=	7,	//修改公告(公告文字)
			cGuildContribute					=	8,	//捐献(数量,类型1银两2元宝)
			cGuildRequestMemberList				=	9,	//请求成员与审核成员列表-------------
			cGuildRequestMember					=	10,	//请求帮派成员页码内容(short index)------------
			cGuildRequestApplicant				=	11,	//请求待审核成员页码内容(short index)-------------
			cGuildRequestUpgrade				=	12,	//请求升级帮派
			cGuildRequestContribData			=	13,	//请求今日捐献数据------------
			cGuildRequestGuildSeller			=	14,	//请求神秘货郎信息------------
			cGuildRequestSellerBuy				=	15,	//购买神秘货郎货物
			cGuildRequestFightFieldData			=	16,	//请求武斗堂数据:(char 0青龙1白虎2朱雀3玄武)--------------
			cGuildRequestFightFieldUpgrade		=	17,	//武斗堂升级(char 0青龙1白虎2朱雀3玄武)
			cGuildSelfFightSkillUpgrade			=	18,	//升级帮派技能(char 0青龙1白虎2朱雀3玄武)

			cGuildRequestSacrificeInfo			=	19,	//请求祭祀信息--------------
			cGuildRequestSacrifice				=	20,	//请求祭祀
			cGuildRequestSetSacrificeTime		=	21,	//设置祭祀时间
			cGuildRequestLuckInfo				=	22,	//请求开运信息-----------------
			cGuildRequestLuck					=	23,	//请求开运
			
			cGuildRequestContribInfo			=	24,	//请求捐献信息
			cGuildGVGApply                      =   25, //攻城战报名
			cGuildGVGJoin                       =   26, //加入攻城战
			cGuildPVGStart                      =   27, //帮会踢馆
			cGuildRequestTiguanGuildList		=	28,	//请求可踢馆帮派列表
			cGuildRequestTiguanMemberList		=	29,	//请求本帮战力排行成员列表
			cGuildRequestTiguanHistory			=	30,	//请求踢馆历史记录
			cGuildReqGVGInfo					=	31,	//请求攻城战信息
			cGuildMonsterOpen					=	32,	//请求神兽战开启
			cGuildMonsterEnter					=	33,	//请求神兽战进入
			cGuildReqMonsterRanking				=	34,	//请求神兽挑战伤害排行
			cGuildGetDailyAward					=	35,	//请求每日福利奖励
			cGuildGetYestodayRankingAward		=	36,	//请求昨日贡献奖励
			cGuildImpeachMaster					=	37,	//请求弹劾帮主
			cGuildReqQifu						=	38,	//请求祈福
			cGuildReqQifuHistory				=	39,	//请求祈福历史
			cGuildReqJiebaiInfo					=	40,	//请求结拜信息
			cGuildReqJiebai						=	41,	//请求进入结拜
			cGuildReqJiebatInvite				=	42,	//请求结拜邀请
			cGuildGetImpeachInfo				=	43,	//请求弹劾帮主信息


			cGuildCityReqReg					=	60,	//注册帮战
			cGuildCityReqEnterDup				=	61,	//进入副本
			cGuildCityGetAward					=	62,	//获取奖励
			cGuildCityOpenMap					=	63, //打开全局地图
			cGuildCityOpenCity					=	64, //打开城镇地图
			cGuildCityOpenReportWin				=	65, //申请打开战报界面
			cGuildCityQueryEnterDup				=	66, //查询是否可以进入副本.


			sGuildSendList						=	1,	//返回:固定数量帮派信息(帮派唯一ID,排名,帮派名,等级,人数,人数上限,帮主,申请状态)
			sGuildRetCreate						=	2,	//创建反馈:0成功,-1失败
			sGuildBaseInfo						=	3,	//帮派基础信息~~~~~~~~~~~~~~~~~
			sGuildMemberList					=	4,	//帮派成员信息~~~~~~~~~~~~~~~~~
			sGuildApplicantList					=	5,	//帮派待审核成员列表~~~~~~~~~~~~~~
			sGuildActionReply					=	6,	//审核,任职,踢人,修改公告等操作的反馈信息
			sGuildApplyReply					=	7,	//申请帮派反馈:0成功,-1超过次数限制,-2帮派不存在,-3已在帮派中,-4等级不符
			sGuildTodayContribData				=	8,	//今日捐献数据~~~~~~~~~~~~~~~~~~
			sGuildSellerInfo					=	9,	//返回神秘货郎信息~~~~~~~~~~~~~~~~~~
			sGuildFightFieldData				=	10,	//武斗堂数据~~~~~~~~~~~~~~~~~~~~
			sGuildSacrificeData					=	11,	//祭祀信息~~~~~~~~~~~~~~~~~~~~
			sGuildLuckData						=	12,	//开运信息~~~~~~~~~~~~~~~~~

			sGuildGVGApplyResult                =   13, //攻城战报名反馈
			sGuildGVGJoinResult                 =   14, //加入攻城战反馈
			sGuildGVGInfo						=   15, //攻城战报名信息

			sGuildMemberJobChanged				=	16, //帮派成员职务改变
			sGuildMemberKick					=	17,	//踢出帮派成员
			sGuildInFlag						=	18, //是否在帮派的标记
			sGuildApplied						=	19,	//通知该帮派已申请

			sGuildPVGStartText                  =   20, //帮会踢馆数据
			sGuildTiguanList					=	21,	//可踢馆帮派列表
			sGuildTiguanMemberList				=	22,	//本帮可出战成员列表
			sGuildTiguanHistory					=	23,	//踢馆历史记录
			sGuildTiguanResult					=	24,	//踢馆结果
			sGuildGVGResult						=	25,	//攻城战结果

			sGuildMonsterFightResult			=	26,	//神兽战结果
			sGuildMonsterKillResutl				=	27,	//神兽战斗结束信息
			sGuildMonsterEnterResult			=	28,	//进入神兽战结果

			sGuildContribHistoryData			=	30,	//捐献历史数据
			sGuildMemberContribData				=	31,	//帮派成员的贡献信息
			sGuildNewMemberData					=	32,	//新增帮派成员数据
			sGuildNotifyModify					=	33,	//公告修改
			sGuildMonsterState					=	34,	//神兽战开启
			sGuildInMonsterSceneFlag			=	35,	//是否在神兽副本标记
			sGuildMonsterSceneDamage			=	36,	//副本内的神兽伤害排行信息
			sGuildDailyAwardFlag				=	37,	//每日福利领取标记
			sGuildYestodayRankingAwardFlag		=	38,	//昨日贡献排名奖励领取标记
			sGuildMasterChange					=	39,	//帮主改变
			sGuildQifuResult					=	40,	//返回祈福结果与剩余次数
			sGuildQifuHistoryList				=	41,	//祈福历史记录
			sGuildJiebaiInfo					=	42,	//结拜信息
			sGuildJiebaiSuccess					=	43,	//结拜完成
			sGuildJiebaiInvite					=	44,	//结拜邀请
			sGuildImpeachInfo					=	45,	//弹劾帮主信息

			sGuildBroadcastEvent				=	50,	//帮派事件广播

			sGuildNotifyOpenCity				=	60, //帮派争霸图标开关
			sGuildNotifyRegCity					=	61, //帮派报名.
			sGuildCityRepGetAward				=	62, //帮派争霸奖励返回结果
			sGuildCityRepEnterDup				=	63, //进入战场返回结果
			sGuildCityNotifyKillBoss			=	64,	//第一个杀BOSS的提示
			sGuildCityNotifyBossAward			=	65,	//BOSS战的奖励
			sGuildCityNotifyBossResult			=	66,	//公告BOSS战结果
			sGuildCityNotifyGVGOpen				=	67,	//公告攻城战开始
			sGuildCityNotifySerialKill			=	68,	//公告连续击杀
			sGuildCityNotifyGVGResult			=	69,	//公告GVG结果
			sGuildCityNotifyGVGAward			=	70,	//公告最终奖励
			sGuildCityRepMap					=	71, //打开全局地图
			sGuildCityRepCity					=	72, //打开城镇地图
			sGuildCityNotifyGVGDamage			=	73, //GVG伤害榜更新
			sGuildCityNotifyRegEnd				=	74, //提示还有五分钟结束注册
			sGuildCityNotifyKillTower			=	75, //提示杀了塔
			sGuildCityNotifyKillCamp			=	76, //提示杀了大本营
			sGuildCityNotifyGVGCanEnter			=	77, //通知可以进入GVG了
			sGuildCityNotifyCanSelectGVG		=	78, //通知可以进入选择GVG了
			sGuildCityNotifyCanSelectBOSS		=	79, //通知可以进入选择BOSS了
			sGuildCityRetReportWindow			=	80, //通知打开战报面板
			cGuildCityQueryEnterDupRet			=	81, //通知进入副本查询结果
			sGuildMemberInfoChange				=	82,	//帮会玩家信息变更
			sGuildCityStateChange				=	83,	//帮派城市状态改变
			sGuildCityState						=	84,	//帮派城市状态
		};

//		/******************************************************
//		/* 商城系统通讯协议类型
//		/*****************************************************/
		enum ShopCmd
		{
			sRetGoodsInfo		= 1,//商品数据返回
			sRetBuyGoods        = 2,//购买商品结果返回
			sRetExchangeInfo    = 3,//兑换数据返回
			sRetExchangeRes     = 4,//兑换结果返回
			sGoodsInfoUpdate    = 5,//某个商品数据更新（0：删除，1：更新）
			sRetMysteryShopInfo = 6,//神秘商店数据返回
			sRetBuyMysteryGoods = 7,//神秘商店购买物品返回
			sRetMysteryError    = 8,//神秘商店错误码
			sRetExhangeRecord   = 9,//返回兑换商城记录数据

			
			sRepStdShopItemList	=11,//请求静态的商品数据
			sRepShopItemInfoList=12,//返回玩家购买数据列表
			sRepShopItemUpdate	=13,//返回商品数据更新
			sRepBuyShopItem		=14,//返回成功购买商品

			cReqGoodsInfo		= 1,//请求商品数据
			cReqBuyGoods        = 2,//请求购买商品
			cReqExchangeInfo    = 3,//请求兑换数据
			cReqExchange        = 4,//请求兑换物品
			cReqMysteryShopInfo = 6,//请求神秘商店数据
			cReqBuyMysteryGoods = 7,//请求购买神秘商店物品
			cReqExchangeRecord  = 8,//请求已兑换记录数据

			cReqBuyShopItem		=10,	//请求购买商店商品
			cReqMysteryUpdateShopInfo = 11,//请求刷新神秘商店

		};

//		/******************************************************
//		/* 活动系统通讯协议类型
//		/*****************************************************/
		enum ActivityCmd
		{
			sRetGainEnergy		= 1,//神仙鸡获取体力结果返回
			sSendActiOpenInfo   = 2,//发送活动开放信息
			sSendActiOpenChange = 3,//发送活动改变信息
			sSendSpecialActivityList = 4,//发送活动数据列表
			sSendSpecialActivityUpdate = 5,//发送活动
			sSendSpecialActivityAwardUpdate = 6,//发送活动奖励数据
			sSendServerOpenTime	= 7,//开服活动开始结束时间
			sReqHappyLottery	= 8,//开心抽奖奖励返回
			sReqInvestAffirm	= 9,//投资请求确认
			sInvestAwardUpdate	= 10,//奖励更新
			sSendMonthHoursTime = 11,//月卡倒计时
			sReqHappyLotterySec	= 12,//第二版开心抽奖奖励返回
			sSendItemExchange	= 13,//发送道具兑换
			sReqTreasureTreeWater= 14,//奇珍异宝树浇水
			sReqTreasureTreeAward= 15,//奇珍异宝树奖励
			sBroadcastTreasureTree= 16,//奇珍异宝树广播
			sTreasureTreeReset	= 17,//神树重置（重新刷新当前页面）
			sNotifyGoldCardInfo	= 18,//月卡奖励信息
			sGoldCardAwardResult = 19,//领取月卡奖励结果
			sGoldCardOrderInfo	= 20,//月卡预订信息
			sChargeDiscountTime = 21,//充值返利次数
			sChargeDiscountResult = 22,//充值返利抽奖结果
			sChargeDiscountInfo = 23,	//充值返利后玩家充值信息
			sSendServerMergeTime = 24,//合服活动开始结束时间
			sSendSingleRechangeinfo = 25,//发送单笔活动数据
			sUpdateSinglerechageinfo = 26,//更新单笔活动
			sSingleRechangeNotify = 27,//更新单笔活动
			sRepGetCrossRankActiAward = 28,//响应:请求获取跨服排行满足条件奖励(手游原来24)
			sRepGetCrossRankInfoReq = 29, //响应:请求获取排行数据(详细数据)(手游原来25)
			sRepGetCrossSimpleRankInfo = 30,//相应:请求获取排行数据(简单数据[前3名])(手游原来26)


			cReqGainEnergy		= 1,//神仙鸡请求获取体力
			cReqDrawAward		= 2,//领取活动奖励
			cReqCoronaAward		= 3,//领取幸运抽奖奖励
			cReqBuyFoundation	= 4,//购买基金
			cReqSerOpenAty		= 5,//开服活动开始结束时间
			cReqHappyLottery	= 6,//领取开心抽奖奖励
			cReqInvestAffirm	= 7,//投资确认
			cReqFetchInvest		= 8,//领取投资
			cReqInvestAsk		= 9,//等级元宝投资
			cReqMonthHours		= 10,//投资月卡倒计时
			cReqMonthInvestAsk	= 11,//投资月卡充值请求
			cReqHappyLotterySec	= 12,//第二版开心抽奖奖励
			cReqLotteryAward	= 13,//活动抽奖
			cReqTreasureBowl	= 14,//聚宝盆
			cReqItemExchange	= 15,//道具兑换
			cReqTreasureTreeWater= 16,//奇珍异宝树浇水
			cReqTreasureTreeAward= 17,//奇珍异宝树领取奖励
			cReqActiveGoldCard	= 18,//激活月卡
			cReqGoldCardAward	= 19,//领取月卡奖励
			cReqGoldCardOrder	= 20,//请求月卡预订信息
			cReqChargeDiscountTime = 21, //请求充值返利次数
			cReqChargeDiscountRoll = 22, //充值返利抽奖
			cReqChargeGetReturnGold = 23, //获取返利元宝
			cReqSerMergeAty         = 24,//合服活动开始结束时间
			cReqGetSingeRechangeAward = 25,//领取单笔充值奖励
			sReqGetCrossRankActiAward = 26,//请求获取跨服排行满足条件奖励（手游原来24）
			sReqGetCrossRankInfo = 27, //请求获取排行数据(详细数据)（手游原来25）
			sReqGetCrossSimpleRankInfo = 28,//请求获取排行数据(简单数据)（手游原来26）

		};

//		/****************************************************
//		/*多人副本房间系统
//		/****************************************************/
		enum	RoomDupCmd
		{
			sRoomError			=1,	//返回操作错误
			sRoomNotice			=2,	//返回事件通知
			sCharRoomInfoList	=3,	//当前角色保存的副本房间数据
			sCharRoomInfoUpdate	=4,	//玩家角色保存的副本数据更新
			sRoomMemDailyNum	=5, //成员每日次数变更
			sRepRoomList		=10,//返回当前查询的房间队伍列表数据
			sRoomInfo			=11,//返回当前房间数据
			sRoomInviteCharList =12,//返回可邀请的玩家列表
			sRoomIndexUpdate	=13,//房间位置状态更新
			sRepRoomCharInfo	=14,//房间位置玩家数据下发
			sRepRoomEvent		=15,//房间事件下发
			sRoomInviteFrom		=16,//接收来自他人的房间邀请
			sRoomInviteWorld	=17,//广播邀请下发
			sRoomUpdateFightCnt	=18,//更新多人副本挑战次数

			cReqRoomList		=1,	//查看当前副本的队伍房间列表数据
			cQuickEnterRoom		=2,	//快速加入房间
			cCreateRoom			=3,	//创建房间
			cEnterRoom			=4,	//请求加入某个房间
			cCloseMember		=5,	//关闭/开启房间位置
			cKickMember			=6, //踢出房间成员
			cMemberReady		=7,	//准备
			cRoomStart			=8,	//房主开始
			cReqInviteList		=9,	//请求可邀请的玩家列表
			cRoomInvite			=10,//邀请玩家
			cLeaveRoom			=11,//离开房间
			cBuyDailyCount		=12,//购买每日次数
			cReqInviteWorld		=13,//广播邀请
			cFightValLimit		=14,//战力限制
			cRoomAutoStart		=15,//满员自动开始设置
			cBuyAllDailyCount	=16,//购买每日总次数（总次数加1，每个子副本加1）
		};

//		/**********************************
//		/* 体力系统
//		/**********************************/
		enum EnergyCmd
		{
			cEnergyBuy							=	1,//购买体力

			sEnergyBaseInfo						=	1,//发送基础数据(int curEnergy, int energyLimit)
			sEnergyCount						=	2,//当前体力值
			sEnergyBuyReply						=	3,//购买反馈
		};
//		/**********************************
//		/* 奖励系统
//		/**********************************/
		enum DailyAwardCmd
		{
			cGetOnlineAward						=	1,//领取在线奖励
			cGetSeriesAward						=	2,//领取连续登陆奖励
			cGetVipGiftAward					=   3,//领取VIP特权礼包
			cGetRankingAward					=	4,//领取排行版奖励
			cGetLevelAward						=	5,//领取等级礼包
			cGetTrainExp						=	6,//领取练功经验
			cGetTrainInfo						=	7,//请求练功面板信息
			cGetTotalLoginAward					=	8,//请求累计登录礼包
			cGetMonthLoginAward					=	9,//领取月度累计登录礼包（神兵系统）
			cGetMonthLoginAwardRe				=	10,//补领月度累计登录礼包（神笔系统）
			cGetNewOnlineAward					=	11,//领取在线奖励
			cGet360AccelerateBallAward			=	12,//获取360加速球奖励
			cGet360GameCenter					=	13,//获取360游戏中心奖励
			cGetGetBackAward					=	14,//获取资源找回奖励
			cGet360GameCenterRecord				=	15,//发送360游戏中心

			cAppleRecharge						=	80,//AppStore内购完成(int RealGoldCount, int ReceiptData-Length, char ReceiptData[], unsigned int vCode)
			cCommmonRecharge					=	90,//通用的充值处理（针对安卓）

			sRepNewCharAwardInfo				=	1,//返回新手在线礼包数据
			sRepContinueLoginAwardInfo			=	2,//返回每日登陆礼包数据
			sRepRankingAwardInfo				=	3,//返回排行版礼包数据
			sRepVipAwardInfo					=	4,//返回VIP礼包数据
			sRepAwardError						=	5,//返回错误

			sRepTrainExp						=	6,//返回练功经验领取成功
			sRepTrainInfo						=	7,//返回练功面板信息
			sRepLevelAwardInfo					=	8,//返回等级礼包数据
			sRepTotalLoginInfo					=	9,//返回累计登录礼包数据
			sRepMonthLoginInfo					=	10,//返回月度累计登录礼包数据（神兵系统）
			sRepNewOnlineAwardUpdate			=	11,//在线奖励数据更新
			sSendNewOnlineAwardRecord           =   12,//在线奖励领奖记录更新
			sSend360PrivilegeAwardRecord		=	13,//360特权奖励领奖记录更新
			sSend360AccelerateBallAwardRecord	=	14,//发送360加速球奖励
			sSend360GameCenterRecord			=	15,//发送360游戏中心
			sSendGetBackAwardRecord				=	16,//发送资源可找回次数

			sAppleRechargeComplete				=	80,//返回AppStore内购被服务器接受
			sCommmonRechargeComplete			=	90,//返回通用的充值处理被服务器接受
		};
//		/**********************************
//		/* VIP 充值系统
//		/**********************************/
		enum	VipRechargeCmd
		{
			sVipRechargeInfo					=	1,//下发VIP,首冲等信息
			sRepRechargeInfo					=	2,//下发充值通知
			sRepActivityRecharge				=	3,//活动充值数据
			sTotalRechargeGold					=	4,//发送总充值元宝
			sRepVipEndTime						=	5,//下发VIP时间结束
			sRepVipPMCount						=	6,//发送vip客服当前数量

			cReqVipPMCount						=	7,//请求VIP客服发送数量
			cReqFristRechargeAward				=	8,//请求领取首冲奖励
			cReqFRAgainAward					= 9,//请求领取再次充值奖励
			cReqFRSingleAward					= 10,//请求领取单笔充值奖励
			cReqFRDailyAward					= 11,//请求领取每日充值奖励
			cReqFixedChargeAward				= 12,//请求领取小笔充值奖励

		};
//		/**********************************
//		/* 好友系统
//		/**********************************/
		enum FriendCmd
		{
			cGetFriendList                      =   2,//请求好友列表
			cGetNearList                        =   3,//请求附近玩家列表
			cGetContactList                     =   4,//请求联系人列表
			cGetBlackList                       =   5,//请求黑名单列表
			cAddFriend                          =   6,//请求添加好友
			cDelFriend                          =   7,//请求删除好友
			cAddBlack                           =   8,//请求添加黑名单玩家
			cDelBlack                           =   9,//请求删除黑名单玩家
			cFriendWhishper                     =   10,//请求私聊玩家
			cAcceptFriendInvite					=	11,//好友申请确认
			cNotFriendWhisper					=	12,//非好友私聊
			cGetOutlineMsg						=	13,//获取离线消息
			cOutlineWhisper						=	14,//离线私聊

			sRetFriendError                     =   1,//返回错误
			sFriendListRet                      =   2,//返回好友列表
			sNearListRet                        =   3,//返回附近玩家数据
			sContactListRet                     =   4,//返回联系人数据
			sBlackListRet                       =   5,//返回黑名单数据
			sAddFriendRet                       =   6,//添加好友返回
			sDelFriendRet                       =   7,//删除好友返回
			sAddBlackRet                        =   8,//添加黑名单玩家返回
			sDelBlackRet                        =   9,//删除黑名单玩家返回
			sFriendWhishperRet                  =   10,//私聊返回结果
			sAddFriendRet2                      =   11,//别人加自己为好友返回
			sinviteFriendRequest				=	12,//向对方发送好友请求
			sDelContactRet						=	13,//删除联系人返回
			sAddContactRet						=	14,//添加联系人通知
			sFriendWhishperErrRet               =   15,//私聊错误返回结果
			sNotFriendWhishperRet				=	16,//非好友私聊结果返回
			sOutlineMsgRet						=	17,//上线返回离线消息
			sOutlineWhisperRet					=	18,//离线返回自己
			sNoticeOnline						=	19,//通知好友自己上线
		};

//		/**********************************************
//		/* 公告系统
//		/**********************************************/
		enum NotifyCmd
		{
			cGetNotifyDetail					=	1,//请求公告内容
			cNotifyRead							=	2,//通知公告已读

			sSendNotifySerialNumber				=	1,//发送公告序号
			sSendNotifyDetail					=	2,//发送公告详情
			sSendNotifyRead						=	3,//发送哪个公告已读
			sNotifyLoginShowUI					=	4,//登录弹界面
			sSendLevelChangeNotify				=	5,//发送等级
		};

//		/******************************************************
//		/* 钱庄系统命令码
//		/*****************************************************/
		enum MoneyShopCmd
		{
			cReqExchageCoin                     = 1,//请求兑换银两

			sSendExchangeCoin	                = 1,//发送兑换银两结果
			sSendExchangeInfo                   = 2,//发送今日兑换信息
		};
//		/*******************************************/
//		/* 聊天系统
//		/*******************************************/
		enum ChatCmd
		{
			cChatReqAll							= 1,//综合
			cChatReqGuild						= 2,//帮派
			cChatReqTeam						= 3,//组队
			cChatReqWhishper					= 4,//私聊
			cChatRecord							= 5,//语音提示
			cChatReqWorld						= 6,//世界聊天
			cAddManagingAccount					= 7,//设置为管理控制帐号
			cRenameChar							= 8,//改名
			cReqShowItem						= 9,//炫耀物品

			sChatAll							= 1,//综合
			sChatGuild							= 2,//帮派
			sChatTeam							= 3,//组队
			sChatWhishper						= 4,//私聊
			sChatSystem							= 5,//系统
			sChatErrorReply						= 6,//错误反馈
			sChatWorld							= 7,//世界频道
			sChatSystemAlert					= 10,//系统提示
			sCharAutoPlayRecord					= 11,//自动播放语音
			sChatWarningFilterWord				= 12,//关键字过滤警告
			sChatScrollMsg						= 13,//信息反馈（用于旧版本提示）
			sSeverGroupInfo						= 14,//返回服务器组ID信息
			sRenameCharResult					= 15,//改名结果
			sNotifyCharName						= 16,//通知角色名字
			sChatSystem2						= 17,//广播内容ID(获取本地语言包)
			sChatSystemEvilConKillNotify		= 18,//广播恶人谷连杀状态
			sChatSystemEvilStopKillNotify		= 19,//广播恶人谷连杀状态
			sSendShowItem						= 20,//返回炫耀道具

			sMoBaiLuckyAwardNotice				= 97,//膜拜幸运奖励公告(char 排行榜类型, string charname)
			cGetGift							= 98,//领取（序列号）礼包
			sGetGiftRet							= 98,//领取（序列号）礼包返回(int errCode)

			sFCMAlert							= 99,//防沉迷警示(char 防沉迷警示等级, uint 防沉迷在线时间)
			sFCMNotify							= 100,//防沉迷验证提示
			sFCMResult							= 101,//防沉迷验证结果
			cFCMCheck							= 101,//防沉迷验证

			sGetActivityKeyRet					= 102,//第二版激活码返回

		};
//		/*******************************************/
//		/* 扫荡
//		/*******************************************/
		enum MopUpCmd
		{
			cReqMopUpStart						= 1,//请求开始扫荡关卡
			cReqMopUpFinish						= 2,//请求结束扫荡关卡
			cReqMopUpStop						= 3,//请求中断扫荡关卡

			sRepMopUpResult						= 1,//返回扫荡结果
			sRepMopUpStart						= 2,//返回扫荡开始
			sRepMopUpFinish						= 3,//返回扫荡结束
			sRepMopUpInfo						= 4,//返回扫荡信息
		};
//		/************************************************************************/
//		/* 邮件系统
//		/************************************************************************/
		enum MailCmd
		{
			cReqMailDataList					= 1,//请求邮件数据列表
			cReadMail							= 2,//阅读一个邮件
			cReqGetEnclosure					= 3,//提取附件
			cReqDeleteMail						= 4,//删除一个邮件
			cReqDeleteMailAll					= 5,//一键删除
			cReqGetAllEnclosure					= 6,//一键提取

			sNotifyMailRead						= 1,//通知有邮件未读
			sNotifyNewMail						= 2,//通知新收到邮件
			sSendMailDataList					= 3,//发送邮件数据列表
			sSendNewMail						= 4,//发送一封新邮件
			sUpdateMailData						= 5,//更新一个邮件的数据(阅读,取附件,删除等)
			sMailActionReply					= 6,//操作反馈
			sMailState							= 7,//邮箱状态
			sMailDeleteAllNotify				= 8,//一键删除提示信息
		};

//		/************************************************************************/
//		/* 活跃度系统
//		/************************************************************************/
		enum ActiveCmd
		{
			cGetActiveAward		= 1,//领取活跃度奖励
			cGetTrainActiveAward		= 3,//领取练功奖励
			cGetTrainActiveInfo			= 4,//获取练功信息

			sGetActiveAward		= 1,//领取活跃度奖励返回
			sActiveInfo			= 2,//返回活跃度奖励信息
			sGetTrainActiveAward		= 3,//返回领取练功奖励信息
			sGetTrainActiveInfo			= 4,//返回练功信息
		};



//		/************************************************************************/
//		/* 江湖闯荡系统
//		/************************************************************************/
		enum JiangHuCmd
		{
			cReqJiangHuReset					= 1,//请求重置
			cReqJiangHuFight					= 2,//请求闯荡
			cReqJiangHuMopUp					= 3,//请求扫荡
			cReqJiangHuBuyFight					= 4,//购买闯荡次数
			cReqJiangHuBuyReset					= 5,//购买重置次数

			sRepJiangHuInfo						= 1,//返回基础数据
			sRepJiangHuDaily					= 2,//返回日常数据
			sRepJiangHuMopUp					= 3,//返回扫荡数据
			sRepJiangHuError					= 4,//返回错误信息
			sRepJiangHuStageAward				= 5,//返回关卡进度奖励
		};



//		/************************************************************************/
//		/* 日常任务系统命令码
//		/************************************************************************/
		enum DailyQuestCmd
		{
			cDailyQuestDropDice					=	1,//扔骰子
			cDailyQuestRefreshAwardTimes		=	2,//刷新奖励倍数
			cDailyQuestQuit						=	3,//放弃任务
			cDailyQuestQuickDone				=	4,//快速完成
			cDailyQuestGetAward					=	5,//领取进度奖励
			cDailyQuestBuyDice					=	6,//购买骰子
			cDailyQuestSubmit					=	7,//交任务

			sDailyQuestData						=	1,//日常任务数据
			sDailyQuestActionReply				=	2,//操作反馈
			sDailyQuestDicePoint				=	3,//骰子结果
			sDailyQuestAwardQuality				=	4,//奖励刷新结果
			sDailyQuestAwardNotice				=	5,//日常任务奖励显示数据
			sGetAwardResData					=	6,//领取累计日常任务奖励的返回
		};

//		/************************************************************************/
//		/* 守卫剑冢
//		/************************************************************************/
		enum SwordGraveCmd
		{
			cReqSwordGraveFight					= 1,//请求守卫关卡
			cReqSwordGraveMopUp					= 2,//扫荡守卫关卡
			cReqSwordGraveBuyFight				= 3,//购买守卫次数
			cReqSwordGraveRoomList				= 4,//查看当前剑冢房间列表数据
			cQuickEntereSwordGraveRoom			= 5,//快速加入房间
			cCreateSwordGraveRoom				= 6,//创建房间
			cEntereSwordGraveRoom				= 7,//请求加入某个房间
			cSwordGraveKickMember				= 8,//踢出队伍成员
			cSwordGraveMemberReady				 = 9,//准备
			cSwordGraveRoomStart				= 10,//队长开始
			cLeaveSwordGraveRoom				= 11,//离开队伍
			cSwordGraveRoomAutoStart			= 12,//满员自动开始设置
			cSwordGraveRoomLimit				= 13,//战斗力限制设置

			sRepSwordGraveList					= 1,//返回列表数据
			sRepSwordGraveInfo					= 2,//返回单个数据
			sRepSwordGraveDaily					= 3,//返回每日信息
			sRepSwordGraveDupStageAward			= 4,//剑冢副本阶段进度奖励(包含首次通关奖励)
			sRepSowrdGraveError					= 5,//错误信息
			sRepSwordGraveRoomList				= 6,//返回当前查询的剑冢队伍列表数据
			sSwordGraveRoomInfo					= 7,//返回当前剑冢队伍数据
			sSwordGraveRoomEvent				= 8,//剑冢队伍事件下发
			sSwordGraveInviteWorld				= 9,//广播邀请下发
			sSwordGraveRoomUpdate				= 10,//队伍数据更新
		};

//		/************************************************************************/
//		/* 排行榜系统命令码
//		/************************************************************************/
		enum RankSysCmd
		{
			cQueryRankSummary					= 1,//查询排行榜简要信息
			cQueryRankDetail					= 2,//查询指定排行榜数据(char 排行榜类型,int 起始排名, unsigned char 请求数量)
			cExecMoBai							= 3,//进行膜拜(char 排行榜类型)
			cGetMoBaiAward						= 4,//领取膜拜奖励(char 排行榜类型)

			sSendRankSummary					= 1,//发送排行榜简要信息
			sSendRankDetail						= 2,//发送指定排行榜信息(char 排行榜类型,int 起始排名, unsigned char 数据数量, array of 排行数据)
			sResultMoBai						= 3,//膜拜返回(char 排行榜类型, int 错误码, int 下次膜拜时间)
			sResultGetMoBaiAward				= 4,//领取膜拜奖励返回(char 排行榜类型, int 错误码)
		};

		
//		/************************************************************************/
//		/* 世界BOSS
//		/************************************************************************/
		enum WorldBossCmd
		{
			cEnterWorldBossMap					= 1,//进入世界BOSS场景
			cQueryWorldBossResult				= 2,//查询世界BOSS结算数据(int BossId)
			cCallWorldBoss						= 3,//召唤世界BOSS
			cQueryWorldBossInfo					= 4,//查询世界BOSS信息
			cQueryServerTime					= 5, //请求世界boss服务器时间

			sEnterWorldBossMapResult			= 1,//返回进入世界BOSS场景错误码
			sWorldBossNotice					= 2,//世界BOSS公告
			sWorldBossDamageRank				= 3,//发送世界BOSS及时伤害榜
			sWorldBossFinalResult				= 4,//发送世界BOSS结算榜
			sWorldBossFinalNotice				= 5,//发送世界BOSS排名公告
			sWorldBossNoticeOver				= 6,//世界BOSS消失的公告
			sLeaderBossFinalNotice				= 7,//发送武林盟主BOSS排名公告
			sCallWorldBossResult				= 8,//召唤世界boss结果
			sCallWorldBossJoinInfo				= 9,//召唤世界boss参加信息
			sCallWorldBossCallInfo				= 10,//世界BOSS召唤信息
			sCallWorldBossErrCode				= 11,//世界BOSS错误码
			sCallWorldBossUpdateInfo			= 12,//更新世界boss信息
			sWorldBossCallFinalResult			= 13,//发送召唤世界BOSS结算榜
			sWorldBossInitData					= 14,//世界BOSS初始化
			sCallBossFinalNotice				= 15,//发送召唤BOSS排名公告
			sCallBossNotice						= 16,//发送召唤BOSS公告
			sCallBossNoticeOver					= 17,//召唤BOSS消失的公告

		};

//		/************************************************************************/
//		/* 被动（天赋）技能
//		/************************************************************************/
		enum TalentSkillCmd
		{
			cReqTalentSkill						= 1,//请求被动(天赋)技能
			cReqOpenBook						= 2,//请求开启秘籍
			cReqMovesLevelUp					= 3,//请求招式升级或者开启
			cReqResetTalentSkill				= 4,//请求重置秘籍数据
			cReqExchangePoint					= 5,//请求兑换潜能点数

			sRepTalentSkill						= 1,//返回被动(天赋)技能
			sRepOpenBook						= 2,//返回开启秘籍
			sRepMovesLevelUp					= 3,//返回招式升级
			sRepResetTalentSkill				= 4,//返回重置结果
			sRepExchangePoint					= 5,//返回潜能兑换结果
			sRepTalentSkillError				= 6,//返回错误码
		};

//		/************************************************************************/
//		/* 客栈
//		/************************************************************************/
		enum	HotelCmd
		{
			cReqHotelServeCustomer				= 1,	//请求元宝招客
			cReqHotelRefleshCustomer			= 2,	//请求刷新顾客
			cReqHotelEvent						= 3,	//各类型NPC交互请求
			cReqHotelRestRoomIncome				= 4,	//请求打扫房间
			cReqHotelHorseIncome				= 5,	//请求打扫马槽
			cReqCustomerInvestIncome			= 6,	//收取投资收益
			cReqHotelUpgrade					= 7,	//请求升级客栈
			cReqHotelOpenRestRoomPos			= 8,	//请求开启客房位置
			cReqHotelOpenHorsePos				= 9,	//请求开启马槽位置
			cReqHotelEventQuickTime				= 10,	//加速客栈事件时间
			cReqHotelMoraIncome					= 11,	//请求领取猜拳奖金
			cReqHotelBuyHouseMaid				= 12,	//请求托管购买
			cReqHotelGainHouseMaidAward			= 13,	//请求领取托管奖励
			cReqNewInvestIncome					= 14,	//收取新版投资收益

			sRepHotelBasicInfo					= 1,	//返回基础信息
			sRepHotelCustomerList				= 2,	//返回顾客列表
			sRepHotelCustomerEventList			= 3,	//返回顾客事件列表
			sRepHotelCustomerUpdate				= 4,	//返回顾客信息更新
			sRepHotelEventUpdate				= 5,	//返回事件更新(根据类型和位置索引定位数据更新)
			sRepHotelResult						= 6,	//返回操作结果事件
			sRepHotemMoraResult					= 7,	//返回猜拳结果
			sRepHotelBuyHouseMaid				= 8,	//返回购买托管结果
			sRepHotelUpdateAward				= 9,	//更新奖励
			sRepHotelAddAwardRecord				= 10,	//增加奖励记录
			sRepHotelGainHouseMaidAward			= 11,	//获取挂机奖励
			sRepHotelUpdateAwardRecord			= 12,	//批量更新奖励日志
		};

//		/************************************************************************/
//		/* 坐骑
//		/************************************************************************/
		enum MountCmd
		{
			cReqMountBasicInfo                  = 1,//请求坐骑基础信息
			cReqMountRideOn                     = 2,//请求上坐骑
			cReqMountRideOff                    = 3,//请求下坐骑
			cReqMountAdvance                    = 4,//请求进阶
			cReqMountStrong                     = 5,//请求强化
			cReqMountTrain                      = 6,//请求培养
			cReqMountSkillLvlUp                 = 7,//请求升级坐骑技能

			cReqMountActiveEquipPos             = 8,//坐骑激活装备位置
			cReqMountEquipTakeOn                = 9,//穿上装备
			cReqMountEquipTakeOff               = 10,//卸下装备
			cReqMoutnEquipAdvance               = 11,//进阶装备
			cReqMountEquipStrong                = 12,//强化装备
			cReqMountStartJuhun                 = 13,//开始聚魂
			cReqMountGatherJuhun                = 14,//搜集聚魂
			cReqMountRefreshZihun               = 15,//刷新紫魂
			cReqMountGrowJuhun                  = 16,//请求聚魂成长

			sRetMountBasicInfo                  = 1,//返回基础信息
			sRetMountRideOn                     = 2,//返回上坐骑结果
			sRetMountRideOff                    = 3,//返回下坐骑结果
			sRetMountAdvance                    = 4,//返回进阶结果
			sRetMountStrong                     = 5,//返回强化结果
			sRetMountTrain                      = 6,//返回培养结果
			sMountStrongNotice                  = 7,//坐骑强化公告
			sRetMountSkillLvlUp                 = 8,//返回升级坐骑技能结果
			sRetMountSkillInfo                  = 9,//返回坐骑技能数据

			sRetMountRetCode                    = 10,//坐骑装备返回码
			sRetMountActiveEquipPos             = 11,//更新坐骑激活
			sRetMountEquipItems                 = 12,//坐骑装备列表更新
			sRetMountEquipSetItem               = 13,//坐骑装备更新
			sUpdateMountHunRes                  = 14,//更新坐骑蓝魂紫魂
			sRetMountEquipStrong                = 15,//坐骑装备强化返回
			sRetMountEquipAdvance               = 16,//坐骑装备进阶返回

			sRetMountStartJuhun                 = 17,//聚魂开始
			sRetMountJuhunGrow                  = 18,//聚魂成长
			sRetMountRefreshZihun               = 19,//刷新紫魂
			sRetMountGatherHun                  = 20,//完成并搜集魂
		};

//		/************************************************************************/
//		/* 系统开启
//		/************************************************************************/
		enum sysOpenCmd
		{
			cReqSysOpenList                     = 1,//请求系统开启列表
			cAddDoneGuideId						= 2,//增加完成引导ID

			sRetSysOpenList                     = 1,//返回已开启系统列表及功能列表
			sRetNewOpenList                     = 2,//返回新开启系统列表
			sRetNewOpenFuncList                 = 3,//返回新开启功能列表
			sRetCloseSysAndFuncList				= 4,//返回关闭的功能列表
		};



//		/************************************************************************/
//		/* 目标系统
//		/************************************************************************/
		enum sysGoalCmd
		{
			cReqDrawGoalSysAward                = 1,//领取目标系的奖励
			cReqDrawGoalTaskAward               = 2,//领取目标任务的奖励

			sRepGoalSysInfoList					= 1,//返回所有数据
			sRepGoalSysInfoUpdate				= 2,//更新目标系数据
			sRepGoalTaskInfoUpdate				= 3,//更新目标任务数据
			sRepGoalTaskInfoList				= 4,//更新目标任务列表
			sRepGoalError						= 5,//返回错误信息
			sRepGoalDrawAwardItem				= 6,//返回领取结果
		};

//		/************************************************************************/
//		/* 扩展玩法系统
//		/************************************************************************/
		enum ExtendCmd
		{
			cReqXunChong						= 1,//请求训宠
			cReqXunChongTotal					= 2,//请求全部训宠
			cReqXunChongLogInfo					= 3,//请求全局操作记录
			cReqXunChongByGold					= 4,//请求元宝训宠
			cReqGameXunChong					= 5,//请求训宠
			cReqGameFanPai						= 6,//请求翻牌
			cReqGameXiPai						= 7,//请求洗牌
			cReqGameCorona						= 8,//幸运抽奖
			cReqGameFire						= 9,//请求点燃烟花
			cReqGameYuanBaoFire					= 10,//请求元宝点燃烟花
			cReqGameBrights						= 11,//请求璀璨度
			cReqGameCoronaLolity				= 12,//请求全民转转抽奖
			cReqGameCoronaLolityTotalGold		= 13,//请求全民转转抽奖奖池数据
			cReqGameTreasureOpen				= 14,//打开江湖宝藏界面
			//cReqGameTreasureShuffle				= 15,//请求江湖宝藏系统洗牌
			cReqGameTreasureTurnover			= 16,//请求江湖宝藏系统翻牌
			cReqGameTreasureGet					= 17,//请求江湖宝藏系统领取惊喜宝箱
			cLocalCharExceptionResult			= 20,//作弊部分上传
			cReqGoldEggItem						= 21,//请求道具砸金蛋
			cReqGoldEggGold						= 22,//请求元宝砸金蛋
			cReqGoldEggJoyInfo					= 23,//请求欢乐值及奖励信息
			cReqGoldEggJoyAward					= 24,//请求欢乐奖励
			cReqGameFire50                      = 25,//请求点燃烟花

			sRepExtError						= 0,//返回错误
			sRepExtValueList					= 1,//返回数据列表
			sRepExtValueUpdate					= 2,//返回单数据更新
			sRepSelfLogInfo						= 3,//返回自身的操作结果
			sRepTotalLogInfo					= 4,//返回当前的操作记录
			sRepTargetLogInfo					= 5,//返回他人获得珍贵物品的记录
			sRepDaySecond						= 6,
			sRepBrights							= 7,//返回服务器璀璨度
			sRepFireworksOnBrights				= 8,//全服达成目标
			sRepFireworksFireResult				= 9,//点燃烟花的结果
			sRepDiscountList					= 10,//打折信息
			sRepLolityGold						= 11,//全民爱转转获得大奖
			sRepLolityTotalGold					= 12,//全民爱转转奖池基金
			sReqGameTreasureLoad				= 13,//返回玩家登陆传送江湖宝藏数据
			sReqGameTreasureReflashLock			= 14,//解除江湖宝藏系统发送翻牌指令的锁
			sReqGameTreasureTurnover			= 15,//返回请求江湖宝藏系统翻牌
			//sReqGameTreasureGetNormal			= 16,//返回请求江湖宝藏系统领取普通奖励
			sReqGameTreasureGet					= 17,//返回请求江湖宝藏系统领取惊喜宝箱
			sReqGameTreasureFreeTime			= 19,//零点重置江湖宝藏系统的每日免费翻牌次数
			sReqGoldEggJoyInfo					= 20,//返回欢乐值及奖励领取标志位
			sReqGoldEggResult					= 21,//返回砸金蛋结果
			sReqGoldEggJoyAwardInfo				= 22,//砸金蛋欢乐奖励广播信息
			sReqGoldEggJoyAwardResult			= 23,//返回砸金蛋结果
			sRepFireworksFireResult50           = 24,//点燃烟花的结果

		};

//		/************************************************************************/
//		/* 武林盟主
//		/************************************************************************/
		enum LeaderCmd
		{
			cRequestAllInfo						= 0, //请求盟主榜单信息
			cRequestLeaderInfoById				= 1, //请求某个职位的详细信息
			cRequestVoteInfo					= 2, //请求自己被投票的信息
			cRequestJoinElect					= 3, //请求参选
			cRequestVoteTo						= 4, //请求投票
			cRequestViewMyRight					= 5, //请求我的权限;
			cRequestDoRight						= 6, //请求执行权限;
			cRequestEntLeaderDup				= 7, //请求进入武林盟主副本
			cRequestShowJoin					= 8, //请求打开参选界面
			cRequestSendGiftTo					= 9, //请求发送礼物

			sRepLeaderAllInfo					= 0, //返回盟主榜单信息
			sRepLeaderInfoById					= 1, //返回某个职业的详细信息
			sRepLeaderVoteInfo					= 2, //
			sRepLeaderJoinElect					= 3, //返回参选结果
			sRepLeaderVoteTo					= 4, //返回投票结果
			sRepMyLeaderInfo					= 5, //返回我的职位信息.
			sRepLeaderViewMyRight				= 6, //返回查看我的权限
			sRepLeaderDoRight					= 7, //请求执行权限
			sRepLeaderEntDup					= 8, //进入武林盟主副本的返回结果
			sRepShowJoin						= 9, //返回请求加入参选界面.
			sLeaderNotify						= 10, //武陵萌主上线
			sRepSendGiftTo						= 11, //发送礼包返回结果.
			sSendLeaderOpenDuplicateTxt			= 12, //开启活动的公告提示
			sGuildCityOwnerNotify				= 13, //通知城主上线.
		};

//		/************************************************************************/
//		/* 魔尊系统
//		/************************************************************************/
		enum MoZunCmd
		{
			cRequestMoZunRank							= 0, //请求魔尊排行
			cRequestMoZunFeatsAward						= 1, //请求魔尊功勋奖励
			cRequestMoZunFightNor						= 2, //请求挑战魔尊
			cRequestMoZunFightAdv						= 3, //请求血战魔尊
			cRequestMoZunBuyMoToken						= 4, //请求购买魔令
			cRequestMoZunFightScore						= 5, //魔尊积分结算
			cRequestMoZunShare							= 6, //分享魔尊
			cRequestMoZunFoundAward						= 7, //发现奖励
			cRequestMoZunRankIndex						= 8, //请求魔尊排行
			cRequestUpdateMoZunMoToken					= 9, //请求更新魔令
			cRequestMoZunCall							= 10,//请求召唤魔尊
			cRequestMoZunFightAdv1						= 11,//请求决战魔尊

			sRepMoZunInfo								= 0, //发送魔尊初始化信息
			sRepMoZunFound								= 1, //发现魔尊
			sRepMoZunFeatsRank							= 2, //返回魔尊功勋排行
			sRepMoZunMoTokenCount						= 3, //更新魔令数量
			sRepMoZunFeatsUpdate						= 4, //更新功勋值
			sRepMoZunErrCode							= 5, //返回错误码
			sRepMoZunDailyReset							= 6, //清空功勋累积奖励
			sRepMoZunAddFeatsAward						= 7, //增加功勋累积奖励
			sRepMoZunInitFightingData					= 8, //初始化魔尊战斗数据
			sRepMoZunKillCount							= 9, //当日击杀次数
			sRepMoZunFoundCount							= 10, //当日发现次数
			sRepMoZunFightResult						= 11, //记录魔尊击杀结果
			sRepMoZunShowFightResult					= 12, //显示魔尊击杀界面
			sRepMoZunModify								= 13, //魔尊变更通知
			sRepMoZunRemove								= 14, //魔尊删除通知
			sRepMoZunOnline								= 15, //登录初始化好友魔尊信息
			sRepMoZunRankIndex							= 16, //当前排行
			sRepMoZunGMFightInfo						= 17, //返回魔尊战斗信息
			sRepMoZunAwardInfo							= 18, //返回魔尊奖励内容
			sRepMoZunMoTokenBuyCount					= 19, //魔令购买次数
			sRepMoZunYestodayLevel						= 20, //昨日等级
			sRepMoZunUpdateCallData						= 21, //魔尊更新时间
			sRepMoZunUpdateCallMoZun					= 22, //更新召唤魔尊数据
		};

//		/******************************************************
//		/* 心法系统命令码
//		/*****************************************************/
		enum XinFaCmd
		{
			cReqXinFaInfo	    = 1,//请求心法信息
			cReqXinFaLevelUp	= 2,//请求心法升级(seriesId, count, {seriesId})
			cReqXinFaStarUp		= 3,//请求心法冲星(seriesId)
			cReqXinFaCombi		= 4,//请求心法合成(id)
			cReqXinFaExtract	= 5,//请求心法抽取(extractType, times, useGoldFlag)
			cReqXinFaEquip      = 6,//请求装备心法(seriesId, gridInx);
			cReqXinFaDecompose  = 7,//请求分解心法(seriesId)

			sRetXinFaInfo		= 1,//返回心法信息(m_XinFaList, m_EquipXinFaList, m_FormationOpenFlag)
			sRetXinFaLvlUpRes	= 2,//返回心法升级结果(errorCode(0表示成功), UserXinFa)
			sRetXinFaStarUpRes 	= 3,//返回冲星结果(int errorCode(0表示成功))
			sRetXinFaCombiRes	= 4,//返回心法合成结果(int errorCode(0表示成功))
			sRetXinFaExtract	= 5,//返回心法抽取结果(int errorCode(0表示成功))
			sRetXinFaEquip      = 6,//返回装备心法结果
			sNotAddXinFa        = 7,//通知新增心法
			sNotDelXinFa        = 8,//通知删除心法
			sNotAddXinFaDebris  = 9,//通知新增心法碎片
			sNotDelXinFaDebris  =10,//通知删除心法碎片
			sNotDebrisCount     =11,//通知心法碎片个数改变
			sNotPassiSkillChg   =12,//通知被动技能改变
			sNotGridOpen        =13,//通知阵形格子开启
			sNoticeDebrisCombiCount = 14,//通知心法碎片可合成数量
			sRetXinFaDecompose  =15,//返回心法分解结果
		};


//		/*****************************************
//		/*问鼎江湖
//		/*****************************************/
		enum PointsRaceCmd
		{
			cRequestPointsRaceOpenWin		=1, //请求打开主窗口
			cRequestPointsRaceRequestFight	=2, //请求挑战
			cRequestPointsRaceGetRankPage	=3, //请求打开排行榜的页面
			cRequestPointsRaceBuyFire		=4, //请求购买怒气
			cRequestPointsRaceUseFire		=5, //请求使用怒气.
			cRequestPointsRaceBuyOneFire	=6, //请求购买一个怒气
			cRequestPointsRaceSecKill		=7, //请求秒杀挑战

			sRepPointsRaceWin				=1, //返回问鼎江湖主界面;
			sRepPointsRaceWelcomeWin		=2, //返回问鼎江湖欢迎界面;
			sRepPointsRaceAwardWin			=3, //返回奖励界面;
			sRepPointsRaceFightRet			=4, //请求战斗的返回结果
			sRepPointsRacedFightShowAward	=5, //显示结算界面.
			sRepPointsRaceUseFireRet		=6, //使用怒气ITEM的返回结果.
			sRepPointsRaceFightBegin		=7, //开战
			sRepPointsRaceFightRobotData	=8, //机器人数据.
			sRepPointsRacedFightFinish		=9, //战斗结束.
			sRepPointsRaceRankResult		=10,//排行榜数据.
			sRepPointsRacedFightFaildOpneWin=11,//失败也要打开界面
		};



//		/*****************************************
//		/*时装系统
//		/*****************************************/
		enum FashionCmd
		{
			cReqsFashionList				=1, //请求时装列表数据
			cReqsFashionEquip				=2,	//请求装备时装
			cReqsFashionUnEquip				=3,	//请求卸载时装
			cReqsFashionBuy					=4,	//请求购买时装
			cReqsFashionRenewal				=5,	//请求续期时装
			cReqsFashionUpdate				=6,	//请求数据刷新
			
			sRespFashionList				=1, //返回时装列表数据
			sRespFashionUpdate				=2, //返回时装列表数据
			sRespFashionEquip				=3, //返回时装装备数据
			sRespFashionEvent				=4, //返回时装操作事件
		};

//		/*****************************************
//		/*称号系统
//		/*****************************************/
		enum TitleCmd
		{
			cReqsTitleList					=1, //请求称号列表数据
			cReqsTitleEquip					=2,	//请求装备称号
			cReqsTitleUnEquip				=3,	//请求卸载称号
			cReqsTitleHeadShow				=4,	//请求头顶显示
			
			sRespTitleList					=1, //返回称号列表数据
			sRespTitleUpdate				=2, //返回称号更新数据
			sRespTitleEquip					=3, //返回称号装备数据(自己)
			sRespTitleDelete				=4,	//返回称号删除数据
			//广播数据
			sRespTitleOnlineMsg				=5,	//称号在线广播
			sRespTitleRarityMsg				=6,	//称号珍贵广播
			sRespTitleEquipStatus			=7,	//他人称号穿戴更新
		};

//		/*****************************************
//		/*神翼系统
//		/*****************************************/
		enum WingCmd
		{
			cReqWingActivate				=1, //请求激活神翼
			cReqWingEquip					=2, //请求装备神翼
			cReqWingUnEquip					=3, //请求卸下神翼
			cReqWingStrong					=4, //请求强化神翼
			cReqWingAdvance					=5, //请求神翼进阶
			cReqPlumeActivate				=6, //请求彩羽激活
			cReqPlumeStrong					=7, //请求彩羽强化
			cReqWingData					=8, //请求神翼数据
			cHideWing						=9, //请求隐藏神翼（add by 邝俊斌）

			sRetWingErrorMsg				=1, //返回神翼操作错误提示
			sRetWingInfo					=2, //返回神翼数据
			sRetWingEquipInfo				=3, //返回神翼装备信息
			sRetWingStrongInfo				=4, //返回神翼强化信息
			sRetPlumeInfo					=5, //返回彩羽数据
			sRetWingData					=6, //返回神翼系统数据
			sHideWing						=7, //广播隐藏神翼（add by 邝俊斌）
		};

//		/*****************************************
//		/*跨服战
//		/*****************************************/
		enum CrossUnionFightCmd
		{
			//个人战
			cReqsCrossUnionMatch					=1, //匹配
			cReqsCrossUnionInfo						=2,	//请求数据
			cReqsCrossUnionBuyFight					=3,	//购买每日次数
			cReqsCrossUnionMatchStop				=4, //停止匹配

			sRepsCrossUnionInfo						=1,	//跨服系统数据
			sRepsCrossUnionError					=2,	//跨服系统错误
			sRepsCrossUnionTurnBackAward			=3,	//跨服系统奖励回调

			sReqsTransferToServer					=10,	//传送到目标服务器
			sReqsTransferBack						=11,	//传送到原来服务器
			sRepsCrossUnionFightStatus				=12,	//跨服个人站战斗状态
			sRepsCrossUnionFightResult				=13,	//跨服个人站战斗结果
			sRepsCrossUnionFightRobotInfo			=14,	//跨服个人站机器人数据
			//
			sRepsCrossUnionMatchFail				=21,//跨服个人战匹配失败
			sRepsCrossUnionMatchSucc				=22,//跨服个人战匹配成功
		};

//		/*****************************************
//		/*积分兑换
//		/*****************************************/
		enum IntegralExchangeCmd
		{
			cReqIntegralExchangeRefreshItems		= 1, //刷新道具
			cReqIntegralExchangeItems				= 2, //兑换道具

			sRepIntegralExchangeErrCode				= 1, //错误码
			sRepIntegralExchangeTime				= 2, //刷新时间
			sRepIntegralExchangeFlag				= 3, //更新兑换标志
			sRepIntegralExchangeItems				= 4, //更新兑换道具
		};

//		/*****************************************
//		/*转职
//		/*****************************************/
		enum SwitchJobCmd
		{
			cReqSwitchJob							= 1, //请求转职
			cReqOpenJob								= 2, //请求开启职业
			cReqCleanCD								= 3, //清空cd

			sRepSwitchJobInfo						= 1, //转职相关信息
			sRepSwitchJobRetCode					= 2, //转职返回码
			sRepSwitchRet							= 3, //转职返回信息
			sRepOpenJob								= 4, //激活职业
			sRepCleanCD								= 5, //清除职业cd返回
		};


//		/*****************************************
//		/*神兵
//		/*****************************************/
		enum MagicWeaponCmd
		{
			cActiveMagicWeapon						= 1, //激活神兵
			cMagicWeaponEatItem						= 2, //吞噬道具
			cMagicWeaponUpStar						= 3, //升星
			cMagicWeaponActiveTask					= 4, //激活任务
			cMagicWeaponUpgrade						= 5, //升阶段

			sIntiMagicWeaponData					= 1, //初始化神兵数据
			sUpdateMagicWeaponInfo					= 2, //更新神兵信息
			sUpdateMagicWeaponTaskInfo				= 3, //更新神兵任务
			sMagicWeaponRetCode						= 4, //神兵返回码
			sMagicWeaponGainStarExp					= 5, //获得经验奖励
			sUpdateMagicWeaponTaskInfoAll			= 6, //更新神兵任务
		};


//		/*************
//		**木人阵**
//		**************/
		enum ChumpCmd
		{
			cReqCoolChump	=	1,//木人阵cd
			cReqStartChump	=	2,//木人阵开始
			cReqChumpRankData = 3,//木人阵排行
			cReqChumpData	=	4,//木人阵数据
			cReqChumpStageTick	=	5,//木人阵倒计时
			cReqChumpStageEnd	=	6,//木人阵结束

			sReqCoolChump	=	1,//木人阵cd
			sReqStartChump	=	2,//木人阵开始
			sReqChumpRankData	=	3,//木人阵排行
			sReqChumpData		=	4,//木人阵数据
			sReqChumpStageTick	=	5,//木人阵倒计时
			sReqChumpStageEnd	=	6,//木人阵结束
			sReqChumpScrollMsg	=	7,//消息显示
		};



//		/*************
//		*奴隶系统
//		**************/
		enum SlaveCmd
		{
			cSlaveReqSlaveInfo = 1,			//请求奴隶数据
			cSlaveReqSlaveRecomend = 2,		//请求推荐奴隶数据
			cSlaveReqLocusOpen = 3,			//激活矿位
			cSlaveReqLocusUpgrade = 4,		//升级矿位
			cSlaveReqLocusIncome = 5,		//收取资源
			cSlaveReqLoot = 6,				//抢夺奴隶
			cSlaveReqHelp = 7,				//协助他人反抗雇主
			cSlaveReqRevolt = 8,			//反抗雇主
			cSlaveReqSlaverDetail = 9,		//推荐的奴隶详细信息
			cSlaveReqEventList = 10,		//事件列表
			cSlaveReqResetRecomend = 11,	//请求刷新推荐奴隶
			cSlaveReqFreeSlaver = 12,		//请求释放奴隶
			cSlaveReqMolestSlaver = 13,		//请求调戏奴隶
			cSlaveReqArrestSlaver = 14,		//请求抓捕奴隶
			cSlaveReqHelpCharList = 15,		//请求帮助列表
			cSlaveReqHelpSave	=16,		//请求拯救
			cSlaveReqLocusInfo	 = 17,		//请求单个矿位信息
			cSlaveReqMasterInfo = 18,		//请求雇主信息

			sSlaveRepSlaveInfo = 1,			//返回奴隶基础信息数据
			sSlaveRepRecomendInfo = 2,		//返回推荐奴隶数据
			sSlaveRepMasterInfo = 3,		//返回雇主信息数据
			sSlaveRepLocusUpdate = 4,		//矿位更新
			sSlaveRepSlaverDetail = 5,		//推荐奴隶细节数据
			sSlaveRepEventList = 6,			//事件列表
			sSlaveRepEventAdd = 7,			//事件新增
			sSlaveFightRobot	=8,			//下发战斗机器人
			sSlaveFightMonster  =9,			//下发战斗怪物
			sSlaveResult = 10,				//奴隶错误返回
			sSlaveFightResult = 11,			//战斗结果下发
			sSlaveHelpCharList = 12,		//返回获取帮助的玩家列表
			sSlaveHelpFromSlaver = 13,		//收到他人的拯救请求
		};

//		/*************
//		*华山论剑系统
//		**************/
		enum HuashanCmd
		{
			cHsReqRegister = 1,				//请求报名
			cHsReqEnterDuplicate = 2,		//请求进入战场
			cHsReqExitDuplicate = 3,		//请求退出战场
			cHsReqRankData = 4,				//请求论剑霸主数据
			cHsReqBasicInfo = 5,			//请求活动信息（报名状态等）


			sHsRepRegister = 1,				//返回报名数据
			sHsRepEnterDuplicate = 2,		//返回进入信息
			sHsRepExitDuplicate = 3,		//返回退出战场信息
			sHsUpdateFightInfo = 4,			//返回战斗信息
			sHsUpdatePoint = 5,				//更新勋章
			sHsUpdateCountDown = 6,			//更新奖励倒计时间
			sHsUpdateAwardInfo = 7,			//更新奖励内容
			sHsSendRankAward = 8,			//发送排行榜
			sHsRefreshAwardPromt = 9,		//发送给客户端刷新奖励内容
			sHsSendRankData = 10,			//发送论剑霸主数据
			sHsRepBasicInfo	= 11,			//返回活动信息(报名状态)
			sHsUpdateFloor = 12,			//发送进入下一层通知
			sHsUpdateRemainTime = 13,		//副本倒计时
			sHsSendMyRank = 14,				//发送自己排名数据
			sHsSendFightEnd = 15,			//发送战斗结束
			sHsSendPersonalInfo = 16,		//发送玩家战斗信息
			sHsFightBegin = 17,				//战斗开始推送通知
			sHsFightShowName = 18,			//华山战斗是否显示名称
		};

//		/*************
//		*武林夺宝系统
//		**************/
		enum TreasureDuplicateCmd
		{
			cReqEnterTreasureDup	= 1,	///请求进入武林夺宝

			sDupTreasureDupRetCode	= 1,	//返回武林夺宝返回值
			sDupTreasureDupUpdate	= 2,	//返回武林夺宝更新
			sTreasureUpdateTime		= 3,	//返回武林更新时间
			sTreasureDupExit		= 4,	//玩家退出副本
			sTreasureDupDropItem	= 5,	//发送拾取奖励
		};

//		/*************
//		*恶人谷逃杀系统
//		**************/
		enum EvilDupCmd
		{
			cReqEnterDup = 1,	// 请求进入恶人谷副本
			cReqBaseInfo = 2,	// 请求恶人谷基础数据
			cReqRankInfo = 3,	// 请求获取最新排行榜数据
			cReqKingRankInfo = 4, // 请求霸主排行信息

			sRepEnterDup = 1,	// 返回进入恶人副本信息 x
			sRepBaseInfo = 2,	// 返回恶人基础信息 x
			sRepAllRankInfo = 3,// 返回所有人排名信息 x
			sRepKingRankInfo = 4,// 返回霸主排行信息 x

			sRepMyRankInfo = 5, // 返回恶人个人排行信息(面板信息) x
			sRepAwardRemainTime = 6, // 返回奖励剩余时间(面板信息) x
			sRepAwardInfo = 7,	// 返回奖励信息(面板信息) x
			sRepGetAward = 8,	// 返回奖励发放信息(奖励记录同步,同时显示获取奖励)x
			sRepActivityRemainTime = 9,	// 返回活动剩余时间 x

			sRepActivityBegin = 15,	// 返回活动开始
			sRepActivityEnd = 16,	// 返回活动结束
			sRepExitDup = 17,		// 返回退出副本

			sRepShowCrazyEffect = 20,// 显示暴走特效
			sRepGetAllCrazyEffect = 21,// 返回所有存在的暴走特效
		};

//		/*************
//		*宠物系统
//		**************/
		enum PetCmd
		{
			cPetReqEatItem = 1,			//宠物请求吃经验丹(一键升级)
			cPetReqFight = 2,			//宠物出战
			cPetReqEatPet = 3,			//宠物吞噬
			cPetReqBreeding = 4,		//宠物繁殖
			cPetReqMakeBreedingRoom = 5,	//宠物创建繁殖房间
			cPetReqEnterBreedingRoom = 6,	//宠物进入繁殖房间
			cPetReqLeaveBreedingRoom = 7,	//退出繁殖房间
			cPetReqSell = 8,			//请求分解宠物
			cPetReqGainBreedAward = 9,	//领取吞噬奖励
			cPetReqBreedRoomList = 10,	//请求繁殖房间
			cPetReqKickPlayer = 11,		//请求踢出繁殖者
			cPetReqAgreeBreeding = 12,	//同意繁殖
			cPetReqStartBreeding = 13,	//开始繁殖
			cPetReqEnterPetIsland = 14,	//请求进入宠物岛
			cPetReqRandIslandProb = 15,	//请求随机宠物岛事件
			cPetReqCastSkill = 16,		//宠物释放技能
			cPetReqUpdateIslandKill = 17,	//请求更新宠物岛数据
			cPetReqExtract = 18,		//请求宠物抽取(extractType, times, useGoldFlag)
			cPetReqSlotOpen = 19,		//请求宠物阵位开孔

			sPetRepRetCode = 1,			//宠物返回码
			sPetInitData = 2,			//宠物初始化数据
			sPetRepEatItem = 3,			//宠物吃丹返回
			sPetUpdateFightPet = 4,		//更新出战宠物
			sPetRepEatPet = 5,			//宠物吞噬返回
			sPetUpdatePetMapTeam = 6,	//更新宠物图鉴组信息
			sPetUpdatePet = 7,			//增加一只宠物
			sPetDelPet = 8,				//移除一只宠物
			sPetBreeding = 9,			//宠物融合返回
			sPetUpdateMap = 10,			//更新宠物图鉴
			sPetRepRoomList = 11,		//更新宠物列表
			sPetUpdateBaseData = 12,	//更新基础信息
			sPetRepUpdateRoomInfo = 13,	//更新房间信息
			sPetUpdatePetSkill = 14,	//更新宠物技能
			sPetRepIslandKillCnt = 15,	//更新宠物岛击杀数量
			sPetRepPetIslandMode = 16,	//宠物岛模式
			sPetCastSkill = 17,			//宠物在服务端模式下释放技能
			sPetPepUpdateSkillCD = 18,	//更新宠物技能cd
			sPetUpdateIslandKill = 19,	//更新宠物岛击杀数量
			sPetExtractData = 20,		//更新宠物抽取数据
			sPetReqOpenedSlot = 21,		//更新宠物阵位开孔
			sPetExtractRet = 22,		//宠物抽取数据
		};

//		/*************
//		*美人系统
//		**************/
		enum BeautyCmd
		{
			cBeautyReqUp = 1,			//请求上阵
			cBeautyReqOut = 2,			//请求下阵
			cBeautyReqActivate = 3,		//请求激活美人
			cBeautyReqAdvanced = 4,		//请求进阶美人
			cBeautyReqComMeet = 5,		//请求普通邂逅美人
			cBeautyReqAdvancedMeet = 6,	//请求高级邂逅美人
			cBeautyReqBath = 7,			//请求共浴
			cBeautyReqLove = 8,			//请求双休

			cBeautyEquipBead     = 9,//装备灵珠
			cBeautyUnEquipBead = 10,//卸下灵珠
			cBeautyBeadEat = 11,//灵珠吞噬
			cBeautySearchTower = 12,//灵珠塔领悟
			cBeautyCollectBeads = 13,//回收灵珠
			cBeautyBeadTowerInfo = 14,//请求灵珠塔信息
			cBeautyBeadLockChange = 15,//请求更改灵珠锁定状态
			cBeautyBeadEvolve = 16,//请求灵珠进阶

			cBeautyReqTargetAward = 17,//请求目标奖励

			sBeautyEatAllBeadTower = 18,//灵珠塔一键吞噬

/*******************************************************************/
			sBeautyPosList = 1,			//阵位列表
			sBeautyPosUpdate = 2,		//阵位更新
			sBeautyRepActivate = 3,		//激活美人返回
			sBeautyRepAdvanced = 4,		//进阶美人返回
			sBeautyList = 5,			//更新美人列表
			sBeautyUpdate = 6,			//更新美人信息
			sBeautyAbil = 7,			//更新美人系统属性
			sBeautyError = 8,			//美人系统操作错误
			sBeautyRepBath = 9,			//美人浴返回
			sBeautyAddBeauty = 10,		//获得美人
			sBeautyAddBeautyToSoul = 11,//获得美人转化为灵魂石
			sBeautyUpdateMeetTimes = 12,//更新邂逅次数
//			sBeautyUpdateMeetTime = 13,//更新邂逅免费时间
			sBeautyUpdateMeetShop = 14,//更新邂逅商店

			sBeautyAddBead = 15,//增加灵珠
			sBeautyDelBead = 16,//删除灵珠
			sBeautyBeadEat = 17,//灵珠吞噬
			sBeautyEquipBeadChange = 18,//装备灵珠变更
			sBeautyAddBeadList = 19,//增加一组灵珠
			sBeautySearchTower = 20,//灵珠塔领悟返回
			sBeautyBeadTowerInfo = 21,//灵珠塔信息
			sBeautySoulCount = 22,//发送神魂值
			sBeautyLockBeadList = 23,//锁定的灵珠列表
			sBeautyBeadLockChange = 24,//灵珠锁定状态改变
			sBeautyBeadEvolveResult = 25,//灵珠进阶结果返回
			sBeautyBeadEvolveInfo = 26,//灵珠进阶后信息
			sBeautyBeadOpRes = 27,

			sBeautyTargetList = 28,//更新目标列表
			sBeautyTargetUpdate = 29,//更新单个目标

			sBeautyBeadFullInfo = 30, //完整灵珠信息
			sBeautyRetEatAllInfo = 31, //返回一键吞噬结果

		};

		/*************
		*功能预告系统
		**************/
		enum SysPreNoticeCmd
		{
			sSendCurPreNoiteInfo = 1,			//发送当前系统预告
		};
	}
}

#endif
