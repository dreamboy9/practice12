#ifndef _SETTINGS_H
#define _SETTINGS_H

#define SETTING_NAME_LEN 10
#define SETTING_DESC_LEN 100

void initsettings();
void destroysettings();
void listsettings();
struct settings_s settings;

typedef struct setting_s
{
    char desc[SETTING_DESC_LEN];
    char name[SETTING_NAME_LEN];
    float value;
    float min;
    float max;
    float step;
} setting_t;

typedef struct settings_s
{
    setting_t *aimbot;
    setting_t *drawaimpos;
    setting_t *esp;
    setting_t *font;
    setting_t *glowshells;
    setting_t *radar;
    setting_t *wallhack;
} settings_t;

#endif
