# Mapa

Hashmap in c as warmup for making cooler things.

Theres a few unnecessary gets and stuff but overrall I think its pretty nice for 250~ loc :D

Also includes a few example hash functions: djdb2, fnv, murmur

## Requirements

CMake

The [marrow](https://github.com/JanGolicnik/marrow) header.

## Building

    > mkdir build
    > cd build
    > cmake ..
    > make

The library file will be placed in the newly created build folder.

## Example usage

```c
#include <stdio.h>
#include "include/mapa.h"

int main(int argc, char* argv[])
{
    Mapa* mapa = mapa_create(mapa_hash_MurmurOAAT_32, mapa_cmp_bytes);

    mapa_insert_str(mapa, "sky", "blue");
    mapa_insert_str(mapa, "ocean", "deep");
    mapa_insert_str(mapa, "forest", "green");
    mapa_insert_str(mapa, "fire", "hot");
    mapa_insert_str(mapa, "ice", "cold");
    mapa_insert_str(mapa, "mountain", "high");
    mapa_insert_str(mapa, "desert", "dry");
    mapa_insert_str(mapa, "river", "flow");
    mapa_insert_str(mapa, "cloud", "white");
    mapa_insert_str(mapa, "sun", "bright");

    MapaItem *last_name = mapa_get_str(mapa, "mister");
    if (last_name != NULL) {
        printf("mister: %s\n", last_name->data);
    } else {
        printf("Key 'mister' not found.\n");
    }

    MapaItem *sky_color = mapa_get_str(mapa, "sky");
    if (sky_color != NULL) {
        printf("sky: %s\n", sky_color->data);
    } else {
        printf("Key 'sky' not found.\n");
    }

    mapa_remove_str(mapa, "ocean");

    {
        MapaItem *ocean_depth = mapa_get_str(mapa, "ocean");
        if (ocean_depth != NULL) {
            printf("ocean: %s\n", ocean_depth->data);
        } else {
            printf("Key 'ocean' not found.\n");
        }
    }

    mapa_insert_str(mapa, "ocean", "deep");

    {
        MapaItem *ocean_depth = mapa_get_str(mapa, "ocean");
        if (ocean_depth != NULL) {
            printf("ocean: %s\n", ocean_depth->data);
        } else {
            printf("Key 'ocean' not found.\n");
        }
    }

    mapa_destroy(mapa);

    return 0;
}
```
