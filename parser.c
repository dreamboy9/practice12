#include "cpcheat.h"

void
parseinput(char* input)
{
    if(input[0] == '\0') return;
    else if(input[0] == '.') {
        addline("Forwarding \"%s\" to Engine ..", input);
        Engfuncs.pfnClientCmd(input+1);
    }
    else {
        if(strstr(input, "help") == input) {
            listsettings();
            return;
        }

        unsigned int i;
        unsigned long *settingsarray = (unsigned long*)&settings;

        for(i = 0; i < sizeof(struct settings_s)/4; i++) {
            setting_t *setting = (setting_t*)settingsarray[i];
            if(strstr(input, setting->name)) {
                input += strlen(setting->name);
                while(*input+1 == ' ')
                    input++;
                if(*input == '\0') {
                    addline("> %s is set to %.2f", setting->name, setting->value);
                    return;
                }
                setting->value = atof(input);
                addline("> %s set to %.2f", setting->name, setting->value);
                return;
            }
        }

        addline("> Unknown setting. Use \"help\" command to get a list.");
    }
}
