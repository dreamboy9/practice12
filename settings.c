#include "cpcheat.h"

struct settings_s settings;
setting_t* newsetting(char* name, char* desc, float defval, float minval, float maxval, float step);

void
initsettings()
{
    // name : description : default value : minimum value : maximum value : step
    settings.aimbot = newsetting("aimbot", "Automatically aims at the head of a near enemy player", 1, 0, 1, 1);
    settings.drawaimpos = newsetting("drawaimpos", "Draws the spot the aimbot is going to aim at", 1, 0, 1, 1);
    settings.esp = newsetting("esp", "Displays name and distance of all players", 1, 0, 1, 1);
    settings.font = newsetting("font", "Changes the font that's being used to draw the ESP", 1, 1, 2, 1);
    settings.glowshells = newsetting("glowshells", "Covers the players in transparent shells", 1, 0, 1, 1);
    settings.radar = newsetting("radar", "Replaces the default radar with a detailled one", 0, 0, 1, 1);
    settings.wallhack = newsetting("wallhack", "Makes other players visible through walls", 1, 0, 1, 1);
}

void
destroysettings()
{
    unsigned int i;
    unsigned long *settingsarray = (unsigned long*)&settings;

    for(i = 0; i < sizeof(struct settings_s)/4; i++) {
        setting_t *setting = (setting_t*)settingsarray[i];
        free(setting);
    }
}

void
listsettings()
{
    unsigned int i;
    unsigned long *settingsarray = (unsigned long*)&settings;

    for(i = 0; i < sizeof(struct settings_s)/4; i++) {
        setting_t *setting = (setting_t*)settingsarray[i];
        addline("> setting: %s", setting->name);
        addline("> purpose: %s", setting->desc);
    }
}

setting_t*
newsetting(char* name, char* desc, float defval, float minval, float maxval, float step)
{
    setting_t *newsetting = malloc(sizeof(struct setting_s));
    memset(newsetting, 0, sizeof(struct setting_s));
    strncpy(newsetting->name, name, SETTING_NAME_LEN);
    strncpy(newsetting->desc, desc, SETTING_DESC_LEN);
    newsetting->value = defval;
    newsetting->min = minval;
    newsetting->max = maxval;
    newsetting->step = step;
    return newsetting;
}
