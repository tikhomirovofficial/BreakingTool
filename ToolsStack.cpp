
#include <iostream>
#include "ToolsStack.h"

using std::cout;
using std::endl;

using namespace Tools;

// Конструктор по умолчанию
ToolStack::ToolStack() : top(nullptr), count(0), capacity(100) {
    cout << "Default constructor: empty stack created, capacity = " << capacity << endl;
}

// Параметризованный конструктор с передачей capacity
ToolStack::ToolStack(unsigned capacity) : top(nullptr), count(0) {
    if (!capacity) {
        this->capacity = 10;
        cout << "Capacity cant be less than 1, set to default 10" << endl;
    }
    else {
        this->capacity = capacity;
    }

    cout << "Parameterized constructor: stack created with capacity = " << this->capacity << endl;
}

void ToolStack::copyOther(const ToolStack& other) {
    // Создаем временный стек в обратном порядке, чтобы в объекте был в исходном порядке
    Node* current = other.top;
    Node* bufferStackTop = nullptr;
    int tempCount = 0;

    // Для заполнения временного стека
    while (current != nullptr && tempCount < other.capacity) {

        Node* newNode = new Node;
        newNode->tool = current->tool;
        newNode->prev = bufferStackTop;

        // Перекладываем с вершины исходного в начало временного, заполняя его
        bufferStackTop = newNode;
        current = current->prev;
        tempCount++;
    }

    // Для заполнения реального стека
    while (bufferStackTop != nullptr) {

        Node* newNode = new Node;
        newNode->tool = bufferStackTop->tool;
        newNode->prev = top;

        top = newNode;
        count++;

        // Удаляем элементы временного стека, шагая вниз
        Node* toDelete = bufferStackTop;
        bufferStackTop = bufferStackTop->prev;
        delete toDelete;
    }
};

// Копирующий конструктор
ToolStack::ToolStack(const ToolStack& other) : top(nullptr), count(0), capacity(other.capacity) {
    if (other.top == nullptr) {
        cout << "Copy constructor: empty stack copied, capacity = " << capacity << endl;
        return;
    }

    copyOther(other);

    cout << "Copy constructor: stack copied, size = " << count << ", capacity = " << capacity << endl;
}

// Оператор присваивания
ToolStack& ToolStack::operator = (const ToolStack& other) {
  
    if (this == &other) {
        cout << "Self-assignment detected, operation skipped" << endl;
        return *this;
    }

    copyOther(other);

    return *this;
}


// Деструктор
ToolStack::~ToolStack() {
    clear();
}

// Очистка стека
void ToolStack::clear() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->prev;
        delete temp;
    }
    count = 0;
}

// Добавить элемент в стек
bool ToolStack::push(const BreakingTool& tool) {
    if (isFull()) {
        cout << "Push failed: stack is full (capacity = " << capacity << ")" << endl;
        return false;
    }

    Node* newNode = new Node;
    newNode->tool = tool;
    newNode->prev = top;

    top = newNode;
    count++;

    cout << "Pushed: " << tool.getName() << " (size = " << count << "/" << capacity << ")" << endl;
    return true;
}

// Удалить элемент с вершины стека
bool ToolStack::pop() {
    if (isEmpty()) {
        cout << "Pop failed: stack is empty" << endl;
        return false;
    }

    Node* temp = top;
    top = top->prev;

    cout << "Popped: " << temp->tool.getName() << " (size = " << count - 1 << "/" << capacity << ")" << endl;
    delete temp;
    count--;

    return true;
}

// Вывести стек
void ToolStack::print() const {
    if (isEmpty()) {
        cout << "Stack is empty (capacity = " << capacity << ")" << endl;
        return;
    }

    cout << "\n=== Stack (size: " << count << "/" << capacity << ") ===" << endl;

    Node* current = top;
    int position = 1;

    while (current != nullptr) {
        cout << position << ". ";
        current->tool.logInfo();
        current = current->prev;
        position++;
    }
    cout << "======================" << endl;
}

// Сортировка по урону (по возрастанию)
void ToolStack::sortByDamage() {
    if (count < 2) {
        cout << "Sort: not enough elements to sort" << endl;
        return;
    }

    BreakingTool* arr = this->toArray();

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int currentToolDmg = arr[j].getDamage();
            int nextToolDmg = arr[j + 1].getDamage();

            if (currentToolDmg > nextToolDmg) {
                BreakingTool temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Очищаем стек, запоминая кол-во элементов
    int currentCount = count;
    clear();

    // Создаем новый стек, чтобы самый маленький урон был наверху
    for (int i = currentCount - 1; i >= 0; i--) {
        Node* newNode = new Node;
        newNode->tool = arr[i];
        newNode->prev = top;
        top = newNode;
    }

    // Восстанавливаем count
    this->count = currentCount;

    delete[] arr;
    cout << "Sort: stack sorted by damage (ascending)" << endl;
}

// Поиск элементов по имени
BreakingTool* ToolStack::findByName(const char* name) const {
    if (isEmpty() || name == nullptr) {
        cout << "Search: invalid parameters" << endl;
        return nullptr;
    }

    Node* current = top;

    while (current != nullptr) {
        const char* currentToolName = current->tool.getName();
        bool namesEqual = !strcmp(name, currentToolName);

        if (namesEqual) {
            cout << "Search: found '" << name << "'" << endl << endl;
            return new BreakingTool(current->tool);
        }

        current = current->prev;
    }

    // Элемент не найден
    cout << "Search: '" << name << "' not found" << endl;
    return nullptr;
}

// Получить в виде массива
BreakingTool* ToolStack::toArray() const {
    if (isEmpty()) {
        cout << "ToArray: stack is empty" << endl;
        return nullptr;
    }

    BreakingTool* arr = new BreakingTool[count];
    Node* current = top;

    for (int i = 0; i < count; i++) {
        arr[i] = current->tool;
        current = current->prev;
    }

    cout << "ToArray: created array of " << count << " elements" << endl;
    return arr;
}

// Проверка на пустоту
bool ToolStack::isEmpty() const {
    return top == nullptr;
}

// Проверка на переполнение
bool ToolStack::isFull() const {
    return count >= capacity;
}

// Получить текущий размер
int ToolStack::getSize() const {
    return count;
}

// Получить вместимость
int ToolStack::getCapacity() const {
    return capacity;
}