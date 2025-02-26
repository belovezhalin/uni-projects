#ifndef TABLE_H
#define TABLE_H

class Table {
public:
   Table();
   Table(const Table &t);
   ~Table();
   bool Get(int x, int y) const;
   void Set(int x, int y, bool value);
   int GetWidth() const;
   int GetHeight() const;
   int CountLiveNeighbors(int x, int y) const;
   void AddLine(char *str);

private:
   int mywidth;
   int myheight;
   bool **mycells;
};

#endif
