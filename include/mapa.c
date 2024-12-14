#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <marrow.h>

#define MAPA_INTERNAL
#include "mapa.h"

typedef struct{
  void* key;
  u64 key_size;
  MapaItem item;
} MapaEntry;

typedef struct
{
  MapaEntry* entries;
  u64 capacity;
  u64 size;
} Mapa;
MapaItem* mapa_get(Mapa* mapa, void const* key, u64 key_len);

void internal_mapa_grow(Mapa* mapa)
{
  int new_capacity = mapa->capacity == 0 ? 1 : mapa->capacity * 2;

  MapaEntry *new_entries = realloc(mapa->entries, sizeof(MapaEntry) * new_capacity);

  mapa->entries = new_entries;
  mapa->capacity = new_capacity;
}

bool mapa_insert(Mapa* mapa, void const* key, u64 key_size, void* data, u64 data_size)
{
  MapaItem new_item;
  new_item.data = calloc(data_size, 1);
  memcpy(new_item.data, data, data_size);
  new_item.size = data_size;

  MapaItem *item = mapa_get(mapa, key, key_size);
  if(item)
  {
    free(item->data);
    item->data = new_item.data;
    item->size = new_item.size;
    return true;
  }

  if (mapa->size == mapa->capacity)
    internal_mapa_grow(mapa);

  MapaEntry entry;
  entry.key = calloc(key_size, 1);
  memcpy(entry.key, key, key_size);
  entry.key_size = key_size;
  entry.item = new_item;

  mapa->entries[mapa->size++] = entry;
  return true;
}

bool mapa_insert_str(Mapa* mapa, char const* key, char* data)
{
  return mapa_insert(mapa, key, strlen(key) + 1, data, strlen(data) + 1);
}

MapaItem* mapa_get(Mapa* mapa, void const* key, u64 key_len)
{
  for (int i = 0; i < mapa->size; i++)
  {
    MapaEntry *entry = &mapa->entries[i];
    if (strncmp(entry->key, key, key_len) == 0){
      return &entry->item;
    }
  }
  return NULL;
}

MapaItem* mapa_get_str(Mapa* mapa, void const* key)
{
  return mapa_get(mapa, key, strlen(key) + 1);
}

bool mapa_remove(Mapa* mapa, void const* key, u64 key_len)
{
  return false;
}

bool mapa_remove_str(Mapa* mapa, void const* key)
{
  return false;
}


Mapa* mapa_create()
{
  Mapa* mapa = (Mapa*)calloc(sizeof(Mapa), 1);
  return mapa;
}

bool mapa_destroy(Mapa* mapa)
{
  for (int i = 0; i < mapa->size; i++)
  {
    MapaEntry *entry = &mapa->entries[i];
    free(entry->key);
    free(entry->item.data);
  }

  free(mapa);
  return true;
}
