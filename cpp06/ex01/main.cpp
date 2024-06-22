#include <iostream>
#include "Serializer.h"

int main(void)
{
    Data data;
    data.asciNumber = 65;
    data.character = 'A';

    std::cout << "Data -> " << data.asciNumber << " -> " << data.character << std::endl;

    uintptr_t serialize(Serializer::serialize(&data));
    Data *d(Serializer::deserialize(serialize));
    std::cout << "D -> " << d->asciNumber << " -> " << d->character << std::endl
              << std::endl;
    d->asciNumber++;
    d->character++;
    std::cout << "D -> " << d->asciNumber << " -> " << d->character << std::endl;
    std::cout << "Data -> " << data.asciNumber << " -> " << data.character << std::endl;

    return 0;
}
