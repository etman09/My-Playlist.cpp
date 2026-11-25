
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* next;
};

class Playlist
{
private:
    Node* head;
    int count;

public:

    Playlist()
    {
        head = nullptr;
        count = 0;
    }

    void addSong(string name)
    {
        Node* new_node = new Node;

        new_node->song = name;
        new_node->next = nullptr;

        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            Node* temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = new_node;
        }

        count++;

        cout << "Song added successfully!" << endl;
    }

    void removeSong(string name)
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty" << endl;
            return;
        }

        if (head->song == name)
        {
            Node* first = head;

            head = head->next;

            delete first;

            count--;

            cout << "Song removed successfully!" << endl;
            return;
        }

        Node* current = head;
        Node* prev = head;

        while (current != nullptr &&
               current->song != name)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Song not found" << endl;
        }
        else
        {
            prev->next = current->next;

            delete current;

            count--;

            cout << "Song removed successfully!" << endl;
        }
    }

    void show()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty" << endl;
            return;
        }

        Node* temp = head;
        int number = 1;

        while (temp != nullptr)
        {
            cout << number << ". "
                 << temp->song << endl;

            temp = temp->next;
            number++;
        }
    }

    void countSongs()
    {
        cout << "Number of Songs: "
             << count << endl;
    }

    ~Playlist()
    {
        Node* temp;

        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    Playlist myPlaylist;

    int choice;
    string name;

    do
    {
        cout << "\n===== MY PLAYLIST =====" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Remove Song" << endl;
        cout << "3. Show Playlist" << endl;
        cout << "4. Count Songs" << endl;
        cout << "0. Exit" << endl;

        cout << "Choose your option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:

                cout << "Enter Song Name: ";

                cin.ignore();

                getline(cin, name);

                myPlaylist.addSong(name);

                break;

            case 2:

                cout << "Enter Song Name to Remove: ";

                cin.ignore();

                getline(cin, name);

                myPlaylist.removeSong(name);

                break;

            case 3:

                myPlaylist.show();

                break;

            case 4:

                myPlaylist.countSongs();

                break;

            case 0:

                cout << "Goodbye!" << endl;

                break;

            default:

                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
