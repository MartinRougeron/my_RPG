/*
** EPITECH PROJECT, 2019
** mi.h
** File description:
** lib
*/

#include <unistd.h>
#include <stdlib.h>
#include "stdarg.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "math.h"
#include "struct.h"

#define TIME(x) sfTime_asMilliseconds(sfClock_getElapsedTime(x))
#define clearmorechar() { for (int y = size; y != READ_SIZE; y++)\
morechar[y] = 0; }
#define READ_SIZE  1
#define INVENTORY_SIZE  24
//DEFINE ANIM SPEEM
#define ANIMATTACK  50 //Vitesse par frame de l'anim en millisecond
#define ANIMWALK  250 //Vitesse par frame de l'anim en millisecond
#define ANIMSPELL  100 //Vitesse par frame de l'anim en millisecond
#define NBFRAMESPELL  3 //Nombre de frame pour l'anim spell
#define WIDTHSPELL  30   //LArgeur de l'anim spell
#define MAXMUSIC 8
//DEFINE SPELL
#define FIRESPELLCOST  10
#define FIRESPELLDAMAGE  10
#define ICESPELLCOST  20
#define ICESPELLDAMAGE  20
#define SHIELDSPELLCOST  100
#define SHIELDSPELLDURATION  5000
#define SHIELDSPELLCD  15000
#define LIGHTSPELLCD  15000
#define LIGHTSPELLCOST  10
#define LIGHTSPELLDURATION  5000
#define MAP_POS game->map.map[game->player.position.map]\
[game->player.position.y][game->player.position.x][z][y][x]
#define MOUSE(i) sfMouse_getPosition(i)
#define WINDOW (sfWindow *)game->window
#define DRAW_SHAPE(i, j, k) sfRenderWindow_drawRectangleShape(i, j, k)
#define LOAD_MENU game->menu.menu_load
#define TRIVIATANT game->triviantan
#define PLAYERFACE game->player.face
#define NAME_FT     if (id >= INVENTORY_SIZE)\
        ite.action = initaction(EQUIPED);
#define SET_COLOR sfColor color[2][5] = {{{255, 219, 0, 255},\
    {255, 169, 4, 255},\
    {238, 123, 6, 255}, {161, 36, 36, 255}, {64, 11, 11, 255}}, {\
    {170, 205, 238, 255}, {121, 151, 214, 255}, {91, 115, 180, 255},\
    {0, 61, 107, 255}, {213, 216, 240, 255}}};
#define MUSIC_CHOICE     if (game->pause.status_vol == 0) {\
        sfRenderWindow_drawSprite(game->window, game->pause.volume_high, \
        NULL);\
        for (int i = 0; i < MAXMUSIC; i++)\
            sfMusic_setVolume(game->music[i], 2);\
    }\
    if (game->pause.status_vol == 1) {\
        sfRenderWindow_drawSprite(game->window, game->pause.volume_off, NULL);\
        for (int i = 0; i < MAXMUSIC; i++)\
            sfMusic_setVolume(game->music[i], 0);\
    }\
    if (game->pause.status_vol == 2) {\
        sfRenderWindow_drawSprite(game->window, game->pause.volume_low, NULL);\
        for (int i = 0; i < MAXMUSIC; i++)\
            sfMusic_setVolume(game->music[i], 0.75);\
    }\
    if (game->pause.status_vol == 3) {\
        sfRenderWindow_drawSprite(game->window, game->pause.volume_mid, NULL);\
        for (int i = 0; i < MAXMUSIC; i++)\
            sfMusic_setVolume(game->music[i], 1.25);\
    }
#define LOADTREE char *name[10] = {"ADRENALINE RUSH", "PRESENCE OF MIND",\
    "SECOND WIND",\
    "PARADE", "TRANSCENDENCE", "CRITICAL", "ARCANOPULSE", "LIFESTEAL",\
    "BATTLEFURY", "FINAL CHAPTER"};\
    char *description[10] = {\
        "You will regenerate 50% more energy",\
        "You will regenerate 50% more mana",\
        "You will regenerate your\n\n hp out of combat",\
        "You have 10% chance\n\nto don't take damage",\
        "Your spell have 20%\n\n cooldown reduction",\
        "You can do critical strike\n\n (20% chance, damage x3.5)",\
        "Your spell can deal critical damage\n\n (20% chance, damage x5)",\
        "You will regenerate\n\n 30% of the damage dealt",\
        "You deal 1.5x more\n\n physical damage",\
        "You deal 1.5x more\n\n magic damage"\
    };\
    int dependence[10][5] = {\
        {-1}, {-1}, {ADRENALINE_RUSH, PRESENCE_OF_MIND, -1},\
        {ADRENALINE_RUSH, -1}, {PRESENCE_OF_MIND, -1},\
        {PARADE, -1}, {TRANSCENDENCE, -1}, {SECOND_WIND, -1},\
        {CRITICAL, -1}, {ARCANOPULSE, -1}\
    };\
    char *path[10] = {\
        "assets/skill/adrenaline_rush.png",\
        "assets/skill/presence_of_mind.png",\
        "assets/skill/second_wind.png",\
        "assets/skill/parade.png",\
        "assets/skill/transcendence.png",\
        "assets/skill/critical.png",\
        "assets/skill/arcanopulse.png",\
        "assets/skill/lifesteal.png",\
        "assets/skill/battlefury.png",\
        "assets/skill/final_chapter.png"\
    };\
    char *pathn[10] = {\
        "assets/skill/adrenaline_rush_n.png",\
        "assets/skill/presence_of_mind_n.png",\
        "assets/skill/second_wind_n.png",\
        "assets/skill/parade_n.png",\
        "assets/skill/transcendence_n.png",\
        "assets/skill/critical_n.png",\
        "assets/skill/arcanopulse_n.png",\
        "assets/skill/lifesteal_n.png",\
        "assets/skill/battlefury_n.png",\
        "assets/skill/final_chapter_n.png"\
    };\
    sfVector2f pos[10] = {\
        {700, 765}, {1150, 765}, {925, 565},\
        {700, 565}, {1150, 565}, {700, 365},\
        {1150, 365}, {925, 165}, {700, 165}, {1150, 165}\
    };\
    for (int i = 0; i != NBSKILL; i++) {\
        skill[i].description = my_strdup(description[i]);\
        skill[i].name = my_strdup(name[i]);\
        skill[i].dependence = cpdependence(dependence[i]);\
        skill[i].sprite =\
        loadskill(path[i], (sfVector2f) {1.5625, 1.5625}, pos[i]);\
        skill[i].unlearned =\
        loadskill(pathn[i], (sfVector2f) {1.5625, 1.5625}, pos[i]);\
    }
#define SAVE_CAT     str = my_strcat(str, my_itoa(game->player.tree.point));\
    str = my_strcat(str, ",");\
    str = my_strcat(str, gettreeunlocked(game));\
    str = my_strcat(str, savequest(game));\
    str = my_strcat(str, getinventory(game));

#define M_PI       3.14159265358979323846

//DEFINE MAP
#define MAPMAXX  6
#define MAPMAXY  6

#define TRIVIAMAPX  1
#define TRIVIAMAPY  1

#define HOUSEMAPX  1
#define HOUSEMAPY  1

#define CAPITALMAXX  2
#define CAPITALMAXY  2

#define SAXONMAXX  2
#define SAXONMAXY  1
/*
Size de la map
Ici on aura donc
0-0 0-1 0-2
1-0 1-1 1-2
2-0 2-1 2-2
Dans le fichier ./assets/map
*/
#define MAPTILESX  30 //Nombre de tiles a afficher en x sur chaque map
#define MAPTILESY  30 //Nombre de tiles a afficher en y sur chaque map

#define SHOWDROPTIME  3000
//DEFINE SKILL TREE

#define NBSKILL  10

#define NBHUD  4

#define MAXACTION  4

#define pnj_item(i) game->pnj[game->player.talking].shop[i]

#define pnj_selected game->pnj[game->player.talking]

#define TIMEINCOMBAT  5000

#define getitem game->player.inventory.item

#define NBPARTWALKANIM  7

int isometric;//To know if yhe world is in an isometric mode
void draw_key_right(game_t *);
void damage_ennemie_show(game_t *);
void draw_end(game_t *);
void draw_key_inventory(game_t *);
void draw_pause_0(game_t *);
void draw_pause_1(game_t *);
void draw_pause_2(game_t *);
void draw_pause_3(game_t *);
void quest_nbr(game_t *game, sfSprite **sprite, int nbquest, sfClock *clock);
void selection_music(game_t *game);
sfIntRect dragon_phase(game_t *game, dragon_t *dragon, sfIntRect rect,
int side);
void draw_key_down(game_t *game);
void draw_key_left(game_t *game);
void draw_key_up(game_t *game);
char *concat_save(char *str, game_t *game);
char *getplayerstat(game_t *game);
void load_pnj_normal_4(game_t *game);
void load_pnj_normal_5(game_t *game);
void load_pnj_quest(game_t *game);
void load_pnj_shop(game_t *game);
void load_pnj_normal(game_t *game);
void put_button(game_t *game);
void game_play(game_t *game, sfRenderWindow *window);
void load_ennemy(game_t *game);
void load_main(game_t *game, sfRenderWindow *window);
void set_main(game_t *game);
void load_music(game_t *game);
void allocation(game_t *game);
void load_allocation(game_t *game);
void play(game_t game, sfRenderWindow *window, sfEvent event);
void call_all_load(game_t *game);
void set_view(game_t *game);
void load_music(game_t *game);
void load_window(game_t *game, sfRenderWindow *window);
void allocation_map(game_t *game);
void allocation_ennemy(game_t *game);
void action_pause_input(game_t *game);
void action_input(game_t *game);
int damage_dragon(game_t *, dragon_t *);
void zoom(game_t *game, sfEvent event);
void action_tree_input(game_t *game);
void quest_load(game_t *game);
dragon_t load_dragon(dragon_t dragon);
void quest_zero(game_t *game);
void quest_one(game_t *game);
void quest_two(game_t *game);
void quest_three(game_t *game);
void quest_four(game_t *game);
void quest_five(game_t *game);
void quest_six(game_t *game);
void quest_seven(game_t *game);
void quest_all(game_t *game);
void go_saxon_dalle(game_t *game);
sfVector2f transform_to_isometric_inv(int x, int y);
sfMusic **create_music(char **path, int nb);
void discover_kill(game_t *game);
void discover_shop(game_t *game);
void discover_equip(game_t *game);
void discover_inventory(game_t *game);
void discover_tree(game_t *game);
int choice_arrow(void);
void draw_shop(game_t *game);
void drawiteminfo_pnj(game_t *game, item_t item, sfVector2f pos);
void load_shop(pnj_t *pnj, item_t *item, int *price, int nbitem);
void choice_item(game_t *);
int shop(game_t *game, sfIntRect *rect, int i);
int draw_choice(int pos, int i, game_t *game, sfIntRect *rect);
int buy_item_pnj(game_t *game, int i);
void draw_shop_items(game_t *game, int i);
void draw_spell(game_t *game);
void damage_player_show(game_t *game);
item_t create_item(char **name, armorstyle_t style, itemtype_t type,
itemstat_t stat);
int draw_confirm(game_t *game);
particles *system_particules(int nbr, sfVector2f position, sfColor color);
sfVector2f transform_to_isometric(int x, int y);
void move_iso(game_t *game, int i);
void move_up(game_t *game, float speed, int elapsed);
void move_down(game_t *game, float speed, int elapsed);
void move_right(game_t *game, float speed, int elapsed);
void move_left(game_t *game, float speed, int elapsed);
void drawoutline(game_t *game, sfIntRect rect);
void ennemy_ia(game_t *game);
void print_inventory(game_t *game);
void enemy_life(game_t *game);
void update_particles(particles *system, float delta_time);
sfVector2f rand_angle(int disp);
sfVector2f rand_vector(int disp);
particles *create_particles(size_t size, sfColor color, sfVector2f, int grav);
void draw_particles(particles *this, sfRenderWindow *win);
void set_particles(particles *this, sfVector2f speed, int size, size_t id);
void load_hud(game_t *game);
void drawlife_ennemies(game_t *game,
sfRectangleShape *contour, sfRectangleShape *life);
void drawlife(game_t *game, int i,
sfRectangleShape *contour, sfRectangleShape *life);
void print_life(game_t *game);
void attack_ennemies(game_t *game);
sfFloatRect range_player(game_t *game);
void detect_matching_range(game_t *game, sfFloatRect range);
void draw_blood(game_t *game);
void anim_player_attack(game_t *game, sfIntRect rect);
void anim_ennemy(game_t *game);
sfRenderWindow *genwindow(void);
sfSprite *loadbutton(char *, sfVector2f, sfVector2f);
player_t loadplayer(game_t *game);
void rec_for_color(game_t *game);
sfSprite *loadbutton(char *path, sfVector2f scale, sfVector2f position);
int hittext(sfText *text, sfWindow *window);
sfText *loadtext(char *text_t, sfVector2f scale, sfVector2f position, int i);
void animplayer(game_t *game);
void main_menu(game_t *game);
void bottom_play_action(game_t *game);
void bottom_setting_action(game_t *game);
void bottom_exit_action(game_t *game);
void draw_k_changestance(game_t *game);
void draw_k_down(game_t *game);
void draw_k_up(game_t *game);
void draw_k_left(game_t *game);
void draw_k_right(game_t *game);
void draw_k_inventory(game_t *game);
void draw_k_attack(game_t *game);
void draw_k_parade(game_t *game);
void draw_k_pause(game_t *game);
void draw_k_changespell(game_t *game);
void draw_k_interact(game_t *game);
void all_call_key(game_t *game);
int hitsprite(sfSprite *sprite, sfWindow *window);
void parchemin_action_on(game_t *game);
void parchemin_action_onn(game_t *game);
void parchemin_action_onnn(game_t *game);
void parchment_action_on(game_t *game);
void draw_all_key_text(sfRenderWindow *window, game_t *game);
void parchemin_action_off(game_t *game);
void set_all_key_base(game_t *game);
void all_set_text(game_t *game);
sfText *loadtext_white(char *text_t, sfVector2f scale,
sfVector2f position, int i);
void all_set_buttom(game_t *game);
void all_set_key_text(game_t *game);
void parchment_action_off(game_t *game);
void draw_all_text(game_t *game);
void all_set_key_text_white(game_t *game);
int test(game_t *game);
void bottom_arrow_action(game_t *game);
char *text_key(char *sprite, game_t *game);
char *text_kekeys(char *sprite, game_t *game);
char *text_keyss(char *sprite, game_t *game);
char *text_key_key(char *sprite, game_t *game);
char *text_keys_key(char *sprite, game_t *game);
char *text_k_key(char *sprite, game_t *game);
char *text_k_keys(char *sprite, game_t *game);
char *text_k_keyss(char *sprite, game_t *game);
char *text_ks_keys(char *sprite, game_t *game);
char *text_keys(char *sprite, game_t *game);
char *all_call_char_key(char *sprite, game_t *game);
void parchments_action_on(game_t *game);
void parchments_action_off(game_t *game);
void bottom_arrow_action_play(game_t *game);
void draw_all_play(game_t *game);
void buttom_r_arrow_action_play(game_t *game);
void buttom_l_arrow_action_play(game_t *game);
void changehaircolor(color_t color, sfSprite *player);
void all_call_ckey(game_t *game);
void all_call_else(game_t *game);
void all_parch(game_t *game);
void all_parch_reforged(game_t *game);
void all_set_name(game_t *game);
char text_key_play(char *sprite, game_t *game, int i);
char text_kekeys_play(char *sprite, game_t *game, int i);
int test_reforge(game_t *game);
char text_keyss_play(char *sprite, game_t *game, int i);
void all_char_forname(char *sprite, game_t *game, int i);
void creat_new_name(game_t *game);
char *my_malloc(int i);
void bottom_play_game(game_t *game);
int check_all_key(game_t *game);
setting_t loaddefaultkey(void);
void animplayer(game_t *game);
char *get_next_line(int fd);
char *my_strcat(char *dest, char *src);
int my_getnbr(char const *str);
char *my_itoa(int nb);
char *my_malloc(int size);
void printmap(int **map);
int loadmap(game_t *game);
int my_strlen(char const *str);
char *my_revstr(char *str);
setting_t loaddefaultkey(void);
void changedirplayer(game_t *game, sfIntRect rect);
void changehaircolor(color_t color, sfSprite *player);
void changecolor(game_t *game);
void moveplayer(game_t *game);
void sfSprite_centerorigine(sfSprite *sprite);
void drawerrormsg(sfColor color, char *msg, sfRenderWindow *window,
unsigned int size);
int cmpintrect(sfIntRect rect, sfIntRect rect2);
int cmpvector2f(sfVector2f pos1, sfVector2f pos2);
void gentiles(game_t *game);
void drawmap(game_t *game);
pnj_t loadpnj(char *path, sfVector2f scale, pos_t pos, facing_t face);
void drawpnj(game_t *game);
void animpnj(game_t *game);
void loadallpnj(game_t *game);
int samemap(pos_t tab1, pos_t tab2);
int containsint(int block, int *list);
int isaround(sfSprite *sprite1, sfSprite *sprite2, int pixel);
void interactpnj(game_t *game);
int isattack(game_t *game);
void drawtext(pnj_t *pnj, game_t *game);
char *my_malloc(int size);
void sfText_centerorigine(sfText *sprite);
void sfRectangleShape_centerorigine(sfRectangleShape *sprite);
void castspell(game_t *game, int spell);
spell_t *loadbasicspell(void);
void animspell(game_t *game);
void movespell(game_t *game);
void launchspell(game_t *game);
void clearspell(spell_t *spell);
int islaunch(game_t *game);
void imput(game_t *game, sfEvent event);
void imput(game_t *game, sfEvent event);
tree_t loadskilltree(void);
void displaytree(game_t *game);
int gottheskill(int *tab, int nbr);
sfSprite *loadskill(char *path, sfVector2f scale, sfVector2f position);
sfSprite *loadbutton(char *path, sfVector2f scale, sfVector2f position);
sfText *loadnbofcmpt(char *text_t, sfVector2f position, int i);
int hitsprite(sfSprite *sprite, sfWindow *window);
void inmenutree(game_t *game);
sfText *loadtxtname(char *text_t, sfVector2f position, int i);
int addskill(game_t *game, int y);
int gotdependence(int *dependence, int *unlocked);
void handlemenu(game_t *game);
void regenstamina(game_t *game);
void regenmana(game_t *game);
int canlaunch(game_t *game);
void givegold(game_t *game, int gold);
void dodamageenemie(game_t *game, int enemie, int damage);
sfVector2f convertpos(pos_t pos);
void loadenemie(game_t *game, enemieoption_t option);
void removebackn(char *str);
enemie_t *loadbasicenemie(void);
char *my_strdup(char *str);
int dospellhit(spell_t *spell, game_t *game);
void spellhit(spell_t *spell, game_t *game);
void dropitem(game_t *game, drop_t drop);
void drawdrop(game_t *game, drop_t drop);
sfSprite *loadspriterect(char *path, sfVector2f scale,
sfVector2f position, sfIntRect rect);
void drawxp(game_t *game);
int xpneedtolvl(game_t *game);
void makelevelup(game_t *game);
void gethudtohide(game_t *game);
void sfSprite_setTransparent(sfSprite *sprite, int alpha);
void sfText_setTransparent(sfText *sprite, int alpha, sfColor color);
void drawlevelup(game_t *game);
void levelupscreen(game_t *game);
sfSprite *loadspritenemie(char *path, sfVector2f scale, sfVector2f position);
void loadinventory(player_t *player);
int getnbaction(game_t *game, int index);
action_t *initaction(itemtype_t type);
void clickonitem(game_t *game, int index, sfIntRect hitbox);
void dropitemaction(game_t *game, int index);
int getnbaction(game_t *game, int index);
void equipitemaction(game_t *game, int index);
void unequipitemaction(game_t *game, int index);
void inventoryinput(game_t *game, sfEvent event);
int hitrect(sfIntRect rect, sfRenderWindow *window);
sfRectangleShape *loadui(void);
sfText **loadaction(void);
sfText *createsimpletext(char *text_t, sfVector2f position, int i);
void drawiteminfo(game_t *game, item_t item);
void drawstat(game_t *game);
void getarmorstat(game_t *game);
void regenstat(game_t *game);
void playertakedamage(game_t *game, int damage);
void useaction(game_t *game, int index);
void dorain(game_t *game);
void changeplayertexture(game_t *game);
sfIntRect getrect(int len, int size, int id);
int additem(game_t *game, item_t item);
void all_call_set(game_t *game);
void walkinganim(game_t *game);
void sfRectangleShape_setTransparent(sfRectangleShape *sprite,
sfColor color, int alpha);
void astakedamage(game_t *game);
void magicshield(game_t *game);
void sfCircleShape_centerorigine(sfCircleShape *sprite);
void lightspell(game_t *game);
void processendmsg(game_t *game, int *end, char *str, int *i);
void waitimput(game_t *game);
void drawsuccessmsg(game_t *game);
void set_all_pause(game_t *game);
sfText *loadtext_pause(char *text_t, sfVector2f scale, sfVector2f position,
int i);
sfText *loadtext_pause_white(char *text_t, sfVector2f scale,
sfVector2f position, int i);
int bottom_resume(game_t *game, int select);
int bottom_setting(game_t *game, int select);
void print_pause(game_t *game);
int bottom_exit(game_t *game, int select);
void print_setting(game_t *game);
void bottom_control(game_t *game);
void bottom_cursor_on(game_t *game);
void bottom_volume(game_t *game);
void print_control(game_t *game);
void set_all_control(game_t *game);
void control_k_up(game_t *game);
void set_all_control_key(game_t *game);
void control_k_down(game_t *game);
void control_k_left(game_t *game);
void control_k_right(game_t *game);
void control_k_inventory(game_t *game);
void control_k_attack(game_t *game);
void control_k_parade(game_t *game);
void control_k_pause(game_t *game);
void control_k_changespell(game_t *game);
void control_k_interact(game_t *game);
void control_k_changestance(game_t *game);
int control_all_key_c(game_t *game);
void set_all_control_key_w(game_t *game);
item_t copyexactitem(item_t item);
void centerviewonplayer(game_t *game);
walkanim_t initpart(facing_t face);
void animpart(game_t *game, spell_t spell);
int getequipmentdamage(game_t *game);
void changemapevent(game_t *game);
void playdeadparticule(game_t *game);
void adddeadparticule(game_t *game, sfVector2f enemie,
sfColor color, int time);
triviatant_t loadtriviatan(void);
void triviatanfight(game_t *game);
plasma_t *loadplasma(sfVector2f pos);
plasma_t *moveandrendershoot(game_t *game, plasma_t *bullet);
void addnewshoot(game_t *game);
void addtxtdmg(game_t *game, int damage, sfVector2f pos);
void drawtriviashoot(game_t *game);
void cleartriviatan(game_t *game);
void actiontriv(game_t *game);
void destroy_triviatan(game_t *game);
void triviatan_shoot(game_t *game);
void restarclock(game_t *game);
void drawgold(game_t *game);
int fillmap(game_t *game, int i, int y, int z);
FILE *getfile(int y, int x, int z, char *path);
int getmap(FILE *fd, int **map, int maxy, int maxx);
void loadtriviamap(game_t *game);
void discover_levelup(game_t *game);
void discover_zoom(game_t *game);
sfVector2f moveenemie(game_t *game, int i, sfVector2f posp);
void fillenemie(enemie_t *enemie, FILE *fd);
int my_strncmp(char *s1, char *s2, int n);
void discover_keys(game_t *game);
void savegame(game_t *game);
char *getinventory(game_t *game);
char *my_strncpy(char const *src, int n);
void loadsave(game_t *game, char *path);
char *loadtree(game_t *game, char *str);
void loaditem(game_t *game, char *str);
void setuplightning(game_t *game, sfVector2f pos);
lightning_t play_lightning(game_t *game, lightning_t lightning);
void destroy_lightning(lightning_t lightning);
void damage_lightning(game_t *game, lightning_t *lightning);
void destroy_fireball(fireball_t *fireball);
void add_fireball(game_t *game, sfVector2f pos, sfVector2f dir);
void move_fireball(game_t *game, fireball_t *fireball);
void add_portal(game_t *game, sfVector2f postion, int spawn);
void anim_portal(game_t *game, portal_t *portal);
void draw_dragon(game_t *game, dragon_t *dragon);
dragon_t create_dragon(void);
void anim_dragon(dragon_t *dragon);
void attack_dragon(game_t *game, dragon_t *dragon);
void bosslifebar(game_t *game, int hp, int maxhp);
void clear_dragon(dragon_t *dragon, game_t *game);
void all_set_text_reforge(game_t *game);
void all_set_buttom_reforge(game_t *game);
void all_set_buttom_ref(game_t *game);
void name_norm(game_t *game);
void name_norm_r(game_t *game);
void norm_k_up(game_t *game);
void norm_k_down(game_t *game);
void norm_k_left(game_t *game);
void norm_k_right(game_t *game);
void norm_k_inventory(game_t *game);
void norm_k_attack(game_t *game);
void norm_k_parade(game_t *game);
void norm_k_pause(game_t *game);
void norm_k_changspell(game_t *game);
void norm_k_interact(game_t *game);
void parchemin_action_offf(game_t *game);
void parchemin_action_offff(game_t *game);
int test_reforge_control(game_t *game);
void call_status(game_t *game);
void call_status_else(game_t *game);
void displayminimap(game_t *game);
void drawquest(game_t *game);
int *getactualquest(game_t *game, int *nb);
char *savequest(game_t *game);
char *loadquest(game_t *game, char *str);
void changedirplayer(game_t *game, sfIntRect rect);
void loadcapitalmap(game_t *game);
int isaround_vector(sfFloatRect pos1, sfVector2f pos2, int pixel);
void processteleport(game_t *game);
void bottom_load_action(game_t *game);
void parchemin_action_offfff(game_t *game);
void parchemin_action_onnnn(game_t *game);
void parchment_load_on(game_t *game);
void parchment_load_off(game_t *game);
void bottom_ar_action(game_t *game);
void bottom_game_action(game_t *game);
void bottom_triva_action(game_t *game);
void bottom_dragon_action(game_t *game);
sfText *loadtext_grey(char *text_t, sfVector2f scale,
sfVector2f position, int i);
int got_a_save(void);
void loadgame(game_t *game);
void loadhousemap(game_t *game);
void hairpnj(game_t *game);
void savepnj(game_t *game);
void all_set_load_reforge(game_t *game);
void all_set_load(game_t *game);
int gotitem(game_t *game, char *item);
void quest_secondary_0(game_t *game);
void loadsaxonmap(game_t *game);
void loadfantome(game_t *game);
void loadwatermap(game_t *game);
void saxontoworld(game_t *game);
void worldtosaxon(game_t *game);
void fantometoworld(game_t *game);
void worldtofantome(game_t *game);
void fartoworld(game_t *game);
void worldtofar(game_t *game);
void casefarwater(game_t *game);
void destroy_enemie(game_t *game);
void dodeath(game_t *game);
void loadvolcan(game_t *game);
void worldtovolcan(game_t *game);
int getarmormana(game_t *game);
void all_set_key_text_norm(game_t *game);
void all_set_key_text_norm_white(game_t *game);
void norm_k_attack_r(game_t *game);
void norm_k_parade_r(game_t *game);
void norm_k_pause_r(game_t *game);
void norm_k_changspell_r(game_t *game);
void norm_k_interact_r(game_t *game);
void norm_k_up_r(game_t *game);
void norm_k_down_r(game_t *game);
void norm_k_left_r(game_t *game);
void norm_k_right_r(game_t *game);
void norm_k_inventory_r(game_t *game);
void norm_buttom_play(game_t *game);
void draw_all_text_r(game_t *game);
void draw_all_text_reforge(game_t *game);
void norm_k_changestance(game_t *game);
char *text_k_keys_n(char *sprite, game_t *game);
char *text_k_keys_norm(char *sprite, game_t *game);
sfRectangleShape *loadguitalk(void);
sfText *loadtexttalk(void);
sfVector2f docolidewithblock(game_t *game, sfVector2f pos, sfVector2f posp);
void displaytree_r(game_t *game, sfText *text, sfText *nb);
void norm_k_attack_c(game_t *game);
void norm_k_parade_c(game_t *game);
void norm_k_pause_c(game_t *game);
void norm_k_changespell_c(game_t *game);
void norm_k_interact_c(game_t *game);
void norm_k_attack_c_r(game_t *game);
void norm_k_parade_c_r(game_t *game);
void norm_k_pause_c_r(game_t *game);
void norm_k_changespell_c_r(game_t *game);
void norm_k_interact_c_r(game_t *game);
void menu_pause(game_t *game);
void menu_setting(game_t *game);
void menu_control(game_t *game);
void menu_key(game_t *game);
void menu_inventory(game_t *game);
void menu_skill_tree(game_t *game);
void menu_lvl_up(game_t *game);
void menu_move_anim(game_t *game);
void menu_game(game_t *game);
void menu_game_tuto(game_t *game);
void getitemstat(game_t *game);
int getarmorstamina(game_t *game);
void removeitemstat(game_t *game);
sfIntRect getrectlightning(sfIntRect rect);