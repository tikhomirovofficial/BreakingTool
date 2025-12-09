#pragma once

#include "BreakingTool.h"

using namespace Tools;

struct Node {
    BreakingTool tool;
    Node* prev;
};

class ToolStack {
    private:
        Node* top;
        unsigned capacity;
        unsigned count;

    public:
        // Конструкторы
        ToolStack();
        ToolStack(unsigned  capacity);
        ToolStack(const ToolStack& other);

        ~ToolStack();

        // Добавить элемент в стек
        bool push(const BreakingTool& tool);

        // Забрать элемент с вершины стека
        bool pop();

        // Вывести стек
        void print() const;

        // Сортировка урона
        void sortByDamage();

        // Поиск элементов по имени
        BreakingTool* findByName(const char* name) const;

        // Получить в виде массива
        BreakingTool* toArray() const;

        // Проверка на пустоту
        bool isEmpty() const;

        // Проверка на заполненность
        bool isFull() const;

        // Получить текущий размер
        int getSize() const;

        // Получить вместимость
        int getCapacity() const;

    private:
        // Вспомогательный метод для очистки стека
        void clear();
};