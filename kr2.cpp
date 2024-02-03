#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phoneNumber;
};

void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Введите имя контакта: ";
    std::cin >> newContact.name;
    std::cout << "Введите номер телефона контакта: ";
    std::cin >> newContact.phoneNumber;
    contacts.push_back(newContact);
    std::cout << "Контакт добавлен" << std::endl;
}

void deleteContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Введите имя контакта для удаления: ";
    std::cin >> name;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if ((*it).name == name) {
            contacts.erase(it);
            return;
        }
    }
    std::cout << "Контакт с таким именем не найден." << std::endl;
}

void updateContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Введите имя контакта для обновления: ";
    std::cin >> name;
    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Введите новый номер телефона контакта: ";
            std::cin >> contact.phoneNumber;
            std::cout << "Информация о контакте обновлена" << std::endl;
            return;
        }
    }
    std::cout << "Контакт с таким именем не найден." << std::endl;
}

void printContacts(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "Телефонный справочник пуст." << std::endl;
        return;
    }
    std::cout << "Телефонный справочник:" << std::endl;
    for (const auto& contact : contacts) {
        std::cout << "Имя: " << contact.name << ", Номер телефона: " << contact.phoneNumber << std::endl;
    }
}

int main() {

    setlocale(LC_ALL, "rus");

    std::vector<Contact> contacts;

    void (*functions[])(std::vector<Contact>&) = {addContact, deleteContact, updateContact, printContacts};

    int choice;

    do {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1 - Добавить контакт" << std::endl;
        std::cout << "2 - Удалить контакт" << std::endl;
        std::cout << "3 - Обновить информацию о контакте" << std::endl;
        std::cout << "4 - Вывести информацию обо всех контактах" << std::endl;
        std::cout << "0 - Выйти из программы" << std::endl;
        std::cout << "Выберите один из предолженных вариантов: ";
        std::cin >> choice;

        if (choice > 0 && choice <= 4) {
            functions[choice - 1](contacts);
        }
        else if (choice != 0) {
            std::cout << "Некорректный ввод. Попробуйте снова." << std::endl;
        }
    } while (choice != 0);

    return 0;
}