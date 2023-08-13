#ifndef MAP_H
#define MAP_H

#include <string>

class Map
{
public:

    Map(const std::string& filename);
    int countContinents() const;

private:

    int rows_;
    int cols_;
    int** map_;
    void readMapFromFile(const std::string& filename);
    void DFS(int row, int col, bool** visited) const;
};

#endif // MAP_H
