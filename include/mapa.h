#ifndef MAPA_H
#define MAPA_H

#include <marrow.h>

typedef u64 mapa_size_t;
typedef u64 mapa_hash_t;
typedef mapa_hash_t (*mapa_hash_func)(void const*, mapa_size_t);
typedef u8 (*mapa_cmp_func)(void const*, mapa_size_t, void const*, mapa_size_t);

#ifndef MAPA_INITIAL_CAPACITY
#define MAPA_INITIAL_CAPACITY 1
#endif // MAPA_INITIAL_CAPACITY

#ifndef MAPA_INITIAL_SEED
#define MAPA_INITIAL_SEED 0x9747b28c
#endif // MAPA_INITIAl_SEED

typedef struct {
    void* data;
    mapa_size_t size;
} MapaItem;


#ifndef MAPA_INTERNAL

extern mapa_hash_t mapa_hash_djb2(void const* key, mapa_size_t key_size);
extern mapa_hash_t mapa_hash_fnv(void const* key, mapa_size_t key_size);
extern mapa_hash_t mapa_hash_MurmurOAAT_32(void const* key, mapa_size_t key_size);
extern u8 mapa_cmp_bytes(void const* a, mapa_size_t a_size, void const* b, mapa_size_t b_size);

typedef void Mapa;

extern Mapa* mapa_create(mapa_hash_func hash_func, mapa_cmp_func cmp_func);
extern bool mapa_destroy(Mapa* mapa);

extern bool mapa_insert(Mapa* mapa, void const* key, mapa_size_t key_size, void* data, mapa_size_t data_size);
extern bool mapa_insert_str(Mapa* mapa, char const* key, char* data); //expects null terminated string
struct MapaItem;
extern MapaItem* mapa_get(Mapa* mapa, void const* key, mapa_size_t key_size);
extern MapaItem* mapa_get_str(Mapa* mapa, void const* key); // expects null terminated string
extern bool mapa_remove(Mapa* mapa, void const* key, mapa_size_t key_size);
extern bool mapa_remove_str(Mapa* mapa, void const* key); // expect null terminated string

#endif // MAPA_INTERNAL

#endif // MAPA_H
