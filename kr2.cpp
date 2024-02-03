#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phoneNumber;
};

void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "������� ��� ��������: ";
    std::cin >> newContact.name;
    std::cout << "������� ����� �������� ��������: ";
    std::cin >> newContact.phoneNumber;
    contacts.push_back(newContact);
    std::cout << "������� ��������" << std::endl;
}

void deleteContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "������� ��� �������� ��� ��������: ";
    std::cin >> name;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if ((*it).name == name) {
            contacts.erase(it);
            return;
        }
    }
    std::cout << "������� � ����� ������ �� ������." << std::endl;
}

void updateContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "������� ��� �������� ��� ����������: ";
    std::cin >> name;
    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "������� ����� ����� �������� ��������: ";
            std::cin >> contact.phoneNumber;
            std::cout << "���������� � �������� ���������" << std::endl;
            return;
        }
    }
    std::cout << "������� � ����� ������ �� ������." << std::endl;
}

void printContacts(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "���������� ���������� ����." << std::endl;
        return;
    }
    std::cout << "���������� ����������:" << std::endl;
    for (const auto& contact : contacts) {
        std::cout << "���: " << contact.name << ", ����� ��������: " << contact.phoneNumber << std::endl;
    }
}

int main() {

    setlocale(LC_ALL, "rus");

    std::vector<Contact> contacts;

    void (*functions[])(std::vector<Contact>&) = {addContact, deleteContact, updateContact, printContacts};

    int choice;

    do {
        std::cout << "�������� ��������:" << std::endl;
        std::cout << "1 - �������� �������" << std::endl;
        std::cout << "2 - ������� �������" << std::endl;
        std::cout << "3 - �������� ���������� � ��������" << std::endl;
        std::cout << "4 - ������� ���������� ��� ���� ���������" << std::endl;
        std::cout << "0 - ����� �� ���������" << std::endl;
        std::cout << "�������� ���� �� ������������ ���������: ";
        std::cin >> choice;

        if (choice > 0 && choice <= 4) {
            functions[choice - 1](contacts);
        }
        else if (choice != 0) {
            std::cout << "������������ ����. ���������� �����." << std::endl;
        }
    } while (choice != 0);

    return 0;
}