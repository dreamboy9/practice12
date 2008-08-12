#ifndef _CLIENT_H
#define _CLIENT_H

#define MOD_CS 1
#define MOD_DOD 2
#define MOD_TFC 3
#define MOD_HLDM 4

struct exporttable_s orgexporttable;
struct exporttable_s *exporttable;

void hookclient();
int modid;

#endif
