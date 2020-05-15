/*
** EPITECH PROJECT, 2020
** stuct
** File description:
** struct
*/

#ifndef structrpg
#define structrpg

typedef enum state {WALKING, ATTACK, IDLE, CASTING} state_t;
typedef enum facing {SOUTH, EST, WEST, NORTH} facing_t;
typedef enum color {BLUE, GRAY, YELLOW, GREEN, PURPLE, RED} color_t;
typedef enum selectspell{FIRE, ICE, SHIELD, LIGHT} select_t;
typedef enum stance {MELEE, RANGE} stance_t;
typedef enum enemietype {ZOMBIE, SKELETON, BOSS} enemietype_t;
typedef enum weather {SHINE, RAIN} weather_t;

#define NBRAIN  200

/*
Pour rajouter des enemie suffit de les mettres dans
./.load/enemie.load
En bas du fichier il y a normalement
l'exemple pour le crée
Pas oublie d'ajouter +1 a NBENEMIETOLOAD
Et la classe du mob dans l'enum juste au dessus
*/

#define NBENEMIETOLOAD  18 //SI LIGNE DE AU DESSUS CHANGER CHANGER ICI !!!
#define MAXENEMIE  30 //La structure enemie est malloc de cette taille
//En gros c'est combien d'enemie max on affiche a l'écrant
#define NBMAXENEMIE MAXENEMIE

#define HEIGHT  1080
#define WIDTH   1920
#define GRAVITY  9.8

#define NBPARTSPELL  30

typedef struct part_s {
    sfVertex *vertex;
    float *lifes;
    float life_time;
    sfColor color;
    sfVector2f *speed;
    sfVector2f pos;
    int size;
    int size_part;
    int infinite;
    float gravity;
} particles;
typedef enum skillname {ADRENALINE_RUSH,
                    PRESENCE_OF_MIND,
                    SECOND_WIND, PARADE,
                    TRANSCENDENCE, CRITICAL,
                    ARCANOPULSE, LIFESTEAL,
                    BATTLEFURY,
                    FINAL_CHAPTER} skillname_t;

typedef enum screen {TITLE_SCREEN,
GAME, DEAD, SKILLTREE, INVENTORY, PAUSE, LEVELUP,
SETTING, CONTROL, KEY, END_SCREEN} screen_t;

typedef enum map_s {WORLD, TRIVIATANFIGHT, HOUSE, CAPITAL, SAXON,
FARWATER, FANTOME, VOLCAN} map_s;

#define NBWORLD 8
//Number of worlds : World, Triviatant & House

#define NB_TILES_ISO  4
//Nombre tiles vhargées pour la projection iso

typedef enum boolean {FALSE, TRUE} bool;

typedef enum hudlist {STAT, XP, LOOT, GOLD} hudlist_t;

typedef enum tuto {NO, MOVE, KILL, BUY, INV, EQUIP_TUTO,
ZOOM, LVLUP, TREE, CAPITALE} tuto_t;


typedef enum action {REMOVE, USE, EQUIP, UNEQUIP, NONE} action_t;

typedef enum quest_ {NOT_BEGIN, BEGIN, FINISH} quest_;

typedef enum sound {MAIN_S, SWORD_S,
SELECTION_S, LEVELUP_S, SHOP_S, FIRE_S, ICE_S, BOSS_S} sound_t;

typedef enum itemtype {POTION = -1, HELMET, CHESTPLATE, LEGGINGS,
BOOTS, SWORD, AMULETTE, ARTIFACT1, ARTIFCAT2, ARTIFACT3, EQUIPED,
NOTYPE} itemtype_t;

typedef enum armorstyle {ARMORNONE,
ARMORRED, ARMORBLUE, ARMORSOLDIER} armorstyle_t;

typedef enum trivphase {SHOT, SLEEP, CHARGE, DYING, CLEAR} trivphase_t;

typedef enum dragonphase {FIREBALL, LIGHTNING, PORTAL, WANDERING,
END} dragonphase_t;

#define ACTIONSWORD (action_t[]) {EQUIP, REMOVE, NONE, NONE}
#define ACTIONARMOR (action_t[]) {EQUIP, REMOVE, NONE, NONE}
#define ACTIONAMUQUEST (action_t[]) {EQUIP, NONE, NONE, NONE}
#define ACTIONPOTION (action_t[]) {USE, REMOVE, NONE, NONE}
#define ACTIONUNEQUP (action_t[]) {UNEQUIP, NONE, NONE, NONE}

#define NBSLOT  9

#define NBQUEST  12
#define NBSECONDARY  3

typedef struct mapmax {
    int x;
    int y;
} mapmax_t;

typedef struct map {
    int ******map;
    mapmax_t *max;
} map_t;

#define NBLAYER  2

typedef struct pos {
    map_s map;
    int x;
    int y;
    float onmapx;
    float onmapy;
} pos_t;

typedef struct drop {
    int gold;
    int xp;
} drop_t;

typedef struct lightning {
    sfSprite *sprite;
    sfClock *clockanim;
    sfVector2f pos;
    sfRectangleShape **particule;
    sfClock *clockspeed;
    sfClock *reset;
    sfVector2f *speed;
    sfClock *clockphase;
    bool hit;
} lightning_t;

typedef struct fireball {
    sfSprite *sprite;
    sfClock *move;
    sfClock *clockanim;
    sfVector2f speed;
} fireball_t;

typedef struct portal {
    sfSprite *portal;
    sfClock *anim;
    int spawn;
} portal_t;

typedef struct plasmashot {
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f speed;
} plasma_t;

typedef struct triviatant {
    sfSprite *sprite;
    sfClock *clock;
    sfClock *phasec;
    sfClock *shoot;
    sfClock *anim;
    plasma_t **bullet;
    int health;
    trivphase_t phase;
} triviatant_t;

typedef struct itemstat {
    int armor;
    int health;
    int mana;
    int stamina;
    int damage;
} itemstat_t;

typedef struct walkanim {
    sfRectangleShape *shape;
    sfVector2f speed;
    float y;
    float base;
    float x;
    sfClock *clock;
    int timetostay;
} walkanim_t;

typedef struct menu_play {
    sfSprite *play;
    sfSprite *play_white;
    sfSprite *parchments;
    sfSprite *frame;
    sfSprite *r_arrow;
    sfSprite *l_arrow;
    sfSprite *r_arrow_white;
    sfSprite *l_arrow_white;
    sfSprite *rec;
    sfText *chose_name;
    sfText *white_text;
    int name;
    int test;
} menu_play_t;

typedef struct key_control_w
{
    sfText *k_up_w;
    sfText *k_down_w;
    sfText *k_left_w;
    sfText *k_right_w;
    sfText *k_inventory_w;
    sfText *k_attack_w;
    sfText *k_parade_w;
    sfText *k_pause_w;
    sfText *k_changestance_w;
    sfText *k_interact_w;
    sfText *k_changespell_w;
} key_control_w_t;

typedef struct key_control {
    sfText *k_up;
    sfText *k_down;
    sfText *k_left;
    sfText *k_right;
    sfText *k_inventory;
    sfText *k_attack;
    sfText *k_parade;
    sfText *k_pause;
    sfText *k_changestance;
    sfText *k_interact;
    sfText *k_changespell;
    char *c_up;
    char *c_down;
    char *c_left;
    char *c_right;
    char *c_inventory;
    char *c_attack;
    char *c_parade;
    char *c_pause;
    char *c_changestance;
    char *c_interact;
    char *c_changespell;
    int status;
} key_control_t;

typedef struct control {
    sfText *t_up;
    sfText *t_down;
    sfText *t_left;
    sfText *t_right;
    sfText *t_inventory;
    sfText *t_attack;
    sfText *t_parade;
    sfText *t_pause;
    sfText *t_changestance;
    sfText *t_interact;
    sfText *t_changespell;
    sfText *t_key;
    key_control_t cont;
    key_control_w_t cont_w;
} control_t;
typedef struct pause
{
    sfSprite *pause_sprite;
    sfSprite *volume_off;
    sfSprite *volume_high;
    sfSprite *volume_mid;
    sfSprite *volume_low;
    sfText *resume;
    sfText *resume_white;
    sfText *exit;
    sfText *exit_white;
    sfText *setting;
    sfText *setting_white;
    sfText *pause_text;
    sfText *control;
    sfText *control_white;
    sfText *cursor;
    sfText *cursor_white;
    sfText *volume;
    sfText *volume_white;
    int status_cursor;
    int status_vol;
} pause_t;

typedef struct menu_st {
    sfSprite *arrow;
    sfSprite *arrow_white;
    sfText *t_up;
    sfText *t_down;
    sfText *t_left;
    sfText *t_right;
    sfText *t_inventory;
    sfText *t_attack;
    sfText *t_parade;
    sfText *t_pause;
    sfText *t_changestance;
    sfText *t_interact;
    sfText *t_changespell;
    sfText *t_key;
    sfRectangleShape *rectang;
} menu_st_t;

typedef struct key_set_w
{
    sfText *k_up_w;
    sfText *k_down_w;
    sfText *k_left_w;
    sfText *k_right_w;
    sfText *k_inventory_w;
    sfText *k_attack_w;
    sfText *k_parade_w;
    sfText *k_pause_w;
    sfText *k_changestance_w;
    sfText *k_interact_w;
    sfText *k_changespell_w;
} key_set_w_t;

typedef struct key_set {
    sfText *k_up;
    sfText *k_down;
    sfText *k_left;
    sfText *k_right;
    sfText *k_inventory;
    sfText *k_attack;
    sfText *k_parade;
    sfText *k_pause;
    sfText *k_changestance;
    sfText *k_interact;
    sfText *k_changespell;
    char *c_up;
    char *c_down;
    char *c_left;
    char *c_right;
    char *c_inventory;
    char *c_attack;
    char *c_parade;
    char *c_pause;
    char *c_changestance;
    char *c_interact;
    char *c_changespell;
} key_set_t;
typedef struct menu_load {
    sfText *buttom_load_game;
    sfText *buttom_load_game_white;
    sfSprite *parche;
    sfSprite *aro;
    sfSprite *aro_white;
    sfText *load_game;
    sfText *load_triviatan;
    sfText *load_dragon;
    sfText *load_game_white;
    sfText *load_triviatan_white;
    sfText *load_dragon_white;
    sfText *load_game_grey;
    sfText *load_triviatan_grey;
    sfText *load_dragon_grey;
} menu_load_t;

typedef struct menu {
    sfClock *parch_clock;
    sfSprite *buttom_play_white;
    sfSprite *buttom_play_black;
    sfSprite *buttom_exit_black;
    sfSprite *buttom_exit_white;
    sfSprite *buttom_setting_black;
    sfSprite *buttom_setting_white;
    sfSprite *parchemin;
    sfSprite *fond;
    sfSprite *parchment;
    menu_load_t menu_load;
    menu_st_t menu_st;
    key_set_t key_st;
    key_set_w_t key_set_w;
    menu_play_t menu_pl;
    int parch_1_status;
    int parch_2_status;
    int parch_3_status;
    int parch_4_status;
    int num_key;
    int status_keys;
    int status_game;
    int status_key;
} menu_t;
typedef struct item {
    sfClock *cd;
    char *name;
    int cost;
    char *path;
    char *descrption;
    action_t *action;
    itemstat_t stat;
    armorstyle_t style;
    sfSprite *sprite;
    itemtype_t type;
} item_t;

typedef struct inventory {
    item_t *item;
    sfClock *clockaction;
    int gold;
    int lastclick;
} inv_t;

typedef struct setting {
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode left;
    sfKeyCode right;
    sfKeyCode inventory;
    sfKeyCode attack;
    sfKeyCode map;
    sfKeyCode pause;
    sfKeyCode changestance;
    sfKeyCode interact;
    sfKeyCode changespell;
    sfKeyCode tree;
} setting_t;

typedef struct status {
    int damage;
    int health;
    int maxhealth;
    int stamina;
    int maxstamina;
    int mana;
    int maxmana;
    int armor;
    sfClock *regenstamina;
    sfClock *regenmana;
    sfClock *regenhealth;
} stat_t;

typedef struct spell {
    int damage;
    int cost;
    int cd;
    float speed;
    float range;
    sfSprite *sprite;
    facing_t face;
    sfClock *moveclock;
    sfClock *animclock;
    walkanim_t *part;
    int which;
} spell_t;

typedef struct mage {
    sfClock **cd;
    spell_t *spell;
    select_t select;
    spell_t *loadedspell;
    select_t unlocked;
} mage_t;

typedef struct skill {
    char *name;
    char *description;
    sfSprite *sprite;
    sfSprite *unlearned;
    int *dependence;
} skill_t;

typedef struct skilltree {
    int *unlocked;
    skill_t *skill;
    int point;
    sfClock *clickonmenu;
} tree_t;

typedef struct font {
    sfFont *menu;
} font_t;

typedef struct player {
    char *name;
    pos_t position;
    pos_t old;
    sfSprite *sprite;
    sfClock *animationclock;
    sfClock *moveclock;
    sfClock *clock_attack;
    sfClock *ismoving;
    inv_t inventory;
    stat_t stat;
    facing_t face;
    state_t state;
    sfClock *attackclock;
    sfClock *spellclock;
    sfClock *combat;
    int map;
    mage_t mage;
    int talking;
    int confirm;
    stance_t stance;
    tree_t tree;
    int xp;
    int level;
    drop_t drop;
    int shield;
    sfClock *clockshield;
    int light;
    sfClock *clocklight;
    char *successmsg;
    color_t color;
    int learnmagic;
    int quest;
} player_t;

typedef struct enemie {
    int health;
    int damage;
    int golddrop;
    pos_t position;
    sfSprite *sprite;
    sfClock *clockanimation;
    sfClock *clock_attack;
    sfClock *clockmove;
    sfClock *blood_c;
    drop_t drop;
    facing_t face;
    int maxhealth;
} enemie_t;

typedef struct damage_show
{
    sfClock **text_c;
    sfText **text;
}show_t;


typedef struct quest
{
    quest_ position;
    item_t recompense;
}quest_t;


typedef struct pnj {
    sfSprite *sprite;
    int exist;
    pos_t position;
    char *text;
    int is_shop;
    item_t *shop;
    int nb_item;
    quest_t quest;
    facing_t face;
    sfClock *clockanim;
    sfClock *interaction;
    int pos;
    int *sell;
    int hair;
    int save;
} pnj_t;

typedef struct tiles {
    sfSprite *tiles233;
    sfSprite **tiles_iso;
}  tiles_t;

typedef struct spell_
{
    sfSprite *fire;
    sfSprite *ice;
    sfSprite *shield;
    sfSprite *light;
}spell_ch_t;


typedef struct hud
{
    sfSprite *hud_main;
    sfSprite *hud_main_end;
    sfSprite *life_bar;
    sfSprite *inventory_sprite;
    sfSprite *mana_bar;
    sfSprite *stamina_bar;
    sfSprite *empty_bar;
    sfSprite *mage;
    sfSprite *warrior;
    sfSprite *spell_choice;
    sfIntRect rect;
    spell_ch_t type;
    sfSprite *gold;
    sfText *goldtxt;
}hud_t;

#define DRAGONHEALTH  800
#define TRIVIATANHEALTH  300

typedef struct dragon {
    lightning_t *lightning;
    fireball_t *fireball;
    portal_t *portal;
    sfSprite *dragon;
    sfClock *phase;
    sfClock *anim;
    sfClock *takedmg;
    sfClock *shoot;
    sfClock *die;
    sfVector2f pos;
    dragonphase_t stance;
    int health;
    int maxhealth;
} dragon_t;

typedef struct enemieoption {
    drop_t drop;
    pos_t pos;
    enemietype_t type;
    int damage;
    int health;
} enemieoption_t;

typedef struct game {
    quest_ *all_quest;
    char **quest_description;
    control_t control;
    pause_t pause;
    dragon_t dragon;
    player_t player;
    setting_t key;
    menu_t menu;
    enemie_t *loadedenemie;
    enemie_t *enemie;
    tiles_t tiles;
    pnj_t *pnj;
    int nbpnj;
    map_t map;
    sfRenderWindow *window;
    int *nowalktiles;
    sfSprite *blood;
    hud_t hud;
    screen_t screen;
    bool *hide;
    int lvltogive;
    weather_t weather;
    sfClock *weatherclock;
    int playerpvstart;
    sfView *view;
    show_t damage;
    font_t font;
    walkanim_t **deadanim;
    tuto_t is_tuto;
    triviatant_t triviantan;
    sfMusic **music;
    sound_t selected;
    int first_item;
    int first_lvl;
    int first_pnj;
    int questselect;
    int nbkill;
} game_t;

#endif /* !structrpg */
