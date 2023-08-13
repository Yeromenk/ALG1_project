#include <fstream>
#include <cstring>
#include <stdexcept>
#include "Map.h"

Map::Map(const std::string& filename) : rows_(0), cols_(0), map_(nullptr)
{
    readMapFromFile(filename);
}

void Map::readMapFromFile(const std::string& filename)
{
    std::ifstream infile(filename);

    if (!infile)
    {
        throw std::runtime_error("Error: could not open file " + filename);
    }

    infile >> rows_ >> cols_;
    map_ = new int* [rows_];

    for (int i = 0; i < rows_; i++)
    {
        map_[i] = new int[cols_];
        for (int j = 0; j < cols_; j++)
        {
            char c;
            infile >> c;
            map_[i][j] = c - '0';
        }
    }

    infile.close();
}

int Map::countContinents() const 
{
    int count = 0;
    bool** visited = new bool* [rows_];

    for (int i = 0; i < rows_; i++)
    {
        visited[i] = new bool[cols_];
        std::memset(visited[i], false, cols_ * sizeof(bool));
    }

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            if (map_[i][j] == 1 && !visited[i][j])
            {
                DFS(i, j, visited);
                count++;
            }
        }
    }

    for (int i = 0; i < rows_; i++) {
        delete[] visited[i];
    }

    delete[] visited;
    return count;
}

void Map::DFS(int row, int col, bool** visited) const
{
    visited[row][col] = true;
    static int rowNeighbors[] = { -1, 0, 0, 1 };
    static int colNeighbors[] = { 0, -1, 1, 0 };

    for (int i = 0; i < 4; i++)
    {
        int newRow = row + rowNeighbors[i];
        int newCol = col + colNeighbors[i];

        if (newRow >= 0 && newRow < rows_ && newCol >= 0 && newCol < cols_
            && map_[newRow][newCol] == 1 && !visited[newRow][newCol])
        {
            DFS(newRow, newCol, visited);
        }
    }
}
