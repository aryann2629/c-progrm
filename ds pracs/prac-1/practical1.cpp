#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, choice, pos, value, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\n===== ARRAY OPERATIONS =====\n";
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Traversal\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Insertion
            cout << "Enter position (1 to " << n + 1 << "): ";
            cin >> pos;

            cout << "Enter value to insert: ";
            cin >> value;

            if (pos < 1 || pos > n + 1)
            {
                cout << "Invalid position!\n";
            }
            else
            {
                for (int i = n; i >= pos; i--)
                {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                cout << "Element inserted successfully.\n";
            }
            break;

        case 2:
            // Deletion
            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;

            if (pos < 1 || pos > n)
            {
                cout << "Invalid position!\n";
            }
            else
            {
                for (int i = pos - 1; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }

                n--;

                cout << "Element deleted successfully.\n";
            }
            break;

        case 3:
            // Traversal
            cout << "Array elements are: ";

            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
            break;

        case 4:
            // Search
            cout << "Enter element to search: ";
            cin >> key;

            {
                bool found = false;

                for (int i = 0; i < n; i++)
                {
                    if (arr[i] == key)
                    {
                        cout << "Element found at position " << i + 1 << ".\n";
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Element not found.\n";
                }
            }
            break;

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}