// texture_replace_core.h -- the part of texture_replace that needs no tree headers (texture_replace.cpp explains it)
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
typedef struct TrKey { char name[24]; char key[40]; } TrKey;        // "<name>", "<name>_<crc>"
void tr_init(const char *dir, void (*log)(const char *line));
void tr_rescan(void);                                                // list textures\ again, drop cached files
int tr_key(void *texobj, TrKey *out);                                // 1: the object's source is one the mod keys
void tr_after_upload(void *texobj, const TrKey *k, int dump, int replace, int log_each);
int tr_stats(char *buf, unsigned n);                                 // 1: something happened since the last call
#ifdef __cplusplus
}
#endif
