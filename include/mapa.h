#ifndef MAPA_H
#define MAPA_H

#include <marrow.h>

typedef struct {
    void* data;
    u64 size;
} MapaItem;

#ifndef MAPA_INTERNAL

typedef void Mapa;

extern Mapa* mapa_create();
extern bool mapa_destroy(Mapa* mapa);

extern bool mapa_insert(Mapa* mapa, void const* key, u64 key_size, void* data, u64 data_size);
extern bool mapa_insert_str(Mapa* mapa, char const* key, char* data); //expects null terminated string
extern MapaItem* mapa_get(Mapa* mapa, void const* key, u64 key_size);
extern MapaItem* mapa_get_str(Mapa* mapa, void const* key); // expects null terminated string
extern bool mapa_remove(Mapa* mapa, void const* key, u64 key_size);
extern bool mapa_remove_str(Mapa* mapa, void const* key); // expect null terminated string

#endif // MAPA_INTERNAL

#endif // MAPA_H
