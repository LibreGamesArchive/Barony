/*-------------------------------------------------------------------------------

	BARONY
	File: game.hpp
	Desc: header file for the game

	Copyright 2013-2016 (c) Turning Wheel LLC, all rights reserved.
	See LICENSE for details.

-------------------------------------------------------------------------------*/

#pragma once

// REMEMBER TO CHANGE THIS WITH EVERY NEW OFFICIAL VERSION!!!
#define VERSION "v2.0.3"
#define GAME_CODE

#define MAX_FPS_LIMIT 60

class Entity;

extern list_t steamAchievements;

#define DEBUG 1
#define ENTITY_PACKET_LENGTH 46
#define NET_PACKET_SIZE 512

// impulses (bound keystrokes)
extern Uint32 impulses[NUMIMPULSES];
extern int reversemouse;
extern double mousespeed;

void handleEvents(void);
void startMessages();

extern double camera_shakex;
extern double camera_shakex2;
extern int camera_shakey;
extern int camera_shakey2;

// net packet send
typedef struct packetsend_t {
	UDPsocket sock;
	int channel;
	UDPpacket *packet;
	int num;
	int tries;
	int hostnum;
} packetsend_t;
extern list_t safePacketsSent, safePacketsReceived[MAXPLAYERS];
extern bool receivedclientnum;

extern Entity *hudweapon, *hudarm;

extern Uint32 clientplayer;
extern Sint32 numplayers;
extern Sint32 clientnum;
extern bool intro;
extern int introstage;
extern bool gamePaused;
extern bool fadeout, fadefinished;
extern int fadealpha;
extern Entity *client_selected[MAXPLAYERS];
extern bool inrange[MAXPLAYERS];
extern bool deleteallbuttons;
extern Sint32 client_classes[MAXPLAYERS];
extern Uint32 client_keepalive[MAXPLAYERS];
extern Uint32 portnumber;
extern list_t messages;
extern list_t command_history;
extern node_t *chosen_command;
extern bool command;
extern bool noclip, godmode, buddhamode;
extern bool everybodyfriendly;
extern bool combat, combattoggle;
extern bool assailant[MAXPLAYERS];
extern bool oassailant[MAXPLAYERS];
extern list_t removedEntities;
extern list_t entitiesToDelete[MAXPLAYERS];
extern bool gamepaused;
extern char maptoload[256], configtoload[256];
extern bool loadingmap, loadingconfig;
extern int startfloor;
extern bool skipintro;
extern Uint32 uniqueGameKey;

// definitions
extern bool showfps;
extern double t, ot, frameval[AVERAGEFRAMES];
extern Uint32 cycles, pingtime;
extern Uint32 timesync;
extern double fps;
extern bool shootmode;
#define NUMCLASSES 10
extern char classnames[10][10];
extern char address[64];
extern bool loadnextlevel;
extern int currentlevel;
extern bool secretlevel;
extern bool darkmap;
extern int shaking, bobbing;
extern int musvolume;
extern Entity* openedChest[4];
extern SDL_Surface *title_bmp;
extern SDL_Surface *logo_bmp;
extern SDL_Surface *cursor_bmp;
extern SDL_Surface *cross_bmp;

bool achievementUnlocked(const char *achName);
void steamAchievement(const char *achName);
void steamAchievementClient(int player, const char *achName);
void freePlayerEquipment(int x);
void pauseGame(int mode, int ignoreplayer);
int initGame();
void deinitGame();
Uint32 timerCallback(Uint32 interval, void *param);
void handleButtons(void);
void gameLogic(void);

// behavior function prototypes:
void actAnimator(Entity *my);
void actRotate(Entity *my);
void actLiquid(Entity *my);
void actEmpty(Entity *my);
void actFurniture(Entity *my);
void actMCaxe(Entity *my);
void actDoorFrame(Entity *my);
void actDeathCam(Entity *my);
void actPlayer(Entity *my);
void actPlayerLimb(Entity *my);
void actTorch(Entity *my);
void actDoor(Entity *my);
void actHudWeapon(Entity *my);
void actHudShield(Entity *my);
void actItem(Entity *my);
void actGoldBag(Entity *my);
void actMonster(Entity *my);
void actGib(Entity *my);
Entity *spawnGib(Entity *parentent);
Entity *spawnGibClient(Sint16 x, Sint16 y, Sint16 z, Sint16 sprite);
void serverSpawnGibForClient(Entity *gib);
void actLadder(Entity *my);
void actLadderUp(Entity *my);
void actPortal(Entity *my);
void actWinningPortal(Entity *my);
void actFlame(Entity *my);
void actCampfire(Entity *my);
Entity *spawnFlame(Entity *parentent);
void actMagic(Entity *my);
Entity *castMagic(Entity *parentent);
void actSprite(Entity *my);
void actSleepZ(Entity *my);
Entity *spawnBang(Sint16 x, Sint16 y, Sint16 z);
Entity *spawnExplosion(Sint16 x, Sint16 y, Sint16 z);
Entity *spawnSleepZ(Sint16 x, Sint16 y, Sint16 z);
void actArrow(Entity *my);
void actBoulder(Entity *my);
void actBoulderTrap(Entity *my);
void actHeadstone(Entity *my);
void actThrown(Entity *my);
void actBeartrap(Entity *my);
void actBeartrapLaunched(Entity *my);
void actSpearTrap(Entity *my);
void actWallBuster(Entity *my);
void actWallBuilder(Entity *my);

void startMessages();

#define TOUCHRANGE 32
#define STRIKERANGE 24
#define XPSHARERANGE 256

// function prototypes for charclass.c:
void initClass(int player);

extern char last_ip[64];
extern char last_port[64];

//TODO: Maybe increase with level or something?
//TODO: Pause health regen during combat?
#define HEAL_TIME 600 //10 seconds. //Original time: 3600 (1 minute)
#define MAGIC_REGEN_TIME 300 // 5 seconds

#define DEFAULT_HP 30
#define DEFAULT_MP 30
#define HP_MOD 5
#define MP_MOD 5

#define MAXCHARGE 30 // charging up weapons

extern bool spawn_blood;
extern bool capture_mouse; //Useful for debugging when the game refuses to release the mouse when it's crashed.

#define LEVELSFILE "maps/levels.txt"
#define SECRETLEVELSFILE "maps/secretlevels.txt"
#define LENGTH_OF_LEVEL_REGION 5

#define TICKS_PER_SECOND 50
