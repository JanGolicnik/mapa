#include <stdio.h>
#include "include/mapa.h"

int main(int argc, char* argv[])
{
    Mapa* mapa = mapa_create();

    mapa_insert_str(mapa, "mister", "rabotnik");

    MapaItem *last_name = mapa_get_str(mapa, "mister");

    if(last_name != NULL)
        printf("mister: %s", last_name->data);

    mapa_destroy(mapa);

    return 0;
}
