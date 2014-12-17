#include <string.h>
#include "istring.h"
#include "syslimit.h"
#include "logger.h"

extern ec_map_t ec_msg;
StrPool g_strpool;

int sp_init(StrPool *sp, uint32_t size) {
    //TODO assert
    if (MAX_STRPOOL_SIZE < size) {
        LOGGER_ERR(EC_SP_SIZE, "");
        return -1;
    }
    sp->size = size;
    sp->index = 0;
    sp->base = new char[size];
    if (sp->base == NULL) {
        LOGGER_ERR(EC_OOM, "initializing string pool");
        return -1;
    }
    return 0;
}
char *sp_add(StrPool *sp, const char *str, uint32_t size) { /* size include '\0' */
    //TODO assert
    if (sp->size < sp->index+size) {
        LOGGER_ERR(EC_SP_NEW, "");
        return NULL;
    }
    strcpy(&sp->base[sp->index], str);
    sp->index += size;
    return &sp->base[sp->index-size];
}
void sp_clean(StrPool *sp) {
    //TODO assert
    sp->size = 0;
    sp->index = 0;
    if (sp->base != NULL) {
        delete[] sp->base;
    }
}
