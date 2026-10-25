#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TITLE_LEN 100
#define ARTIST_LEN 100

typedef struct Song {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    struct Song *next;
} Song;

static Song *head = NULL;
static Song *current = NULL;

static void read_line(const char *prompt, char *buffer, size_t size) {
    size_t len;
    int ch;

    printf("%s", prompt);
    if (fgets(buffer, (int)size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }

    len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* discard remaining characters */
        }
    }
}

static int equals_ignore_case(const char *a, const char *b) {
    while (*a != '\0' && *b != '\0') {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {
            return 0;
        }
        ++a;
        ++b;
    }
    return *a == '\0' && *b == '\0';
}

static Song *find_song(const char *title) {
    Song *temp;

    if (head == NULL) {
        return NULL;
    }

    temp = head;
    do {
        if (equals_ignore_case(temp->title, title)) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);

    return NULL;
}

static void add_song(void) {
    Song *new_song;
    Song *tail;

    new_song = (Song *)malloc(sizeof(Song));
    if (new_song == NULL) {
        printf(" Song was not added.\n");
        return;
    }

    read_line("Enter song title: ", new_song->title, sizeof(new_song->title));
    if (new_song->title[0] == '\0') {
        printf("Song title cannot be empty.\n");
        free(new_song);
        return;
    }

    read_line("Enter artist name: ", new_song->artist, sizeof(new_song->artist));
    if (new_song->artist[0] == '\0') {
        (void)snprintf(new_song->artist, sizeof(new_song->artist), "%s", "Unknown artist");
    }

    if (head == NULL) {
        head = new_song;
        new_song->next = head;
        current = head;
    } else {
        tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = new_song;
        new_song->next = head;
    }

    printf("Song added successfully.\n");
}

static void display_playlist(void) {
    Song *temp;
    int number = 1;

    if (head == NULL) {
        printf("Playlist is empty. Add some songs first.\n");
        return;
    }

    printf("\n======= MUSIC PLAYLIST =======\n");
    temp = head;
    do {
        printf("%d. %s - %s", number, temp->title, temp->artist);
        if (temp == current) {
            printf("  [CURRENT]");
        }
        printf("\n");
        ++number;
        temp = temp->next;
    } while (temp != head);
    printf("====================================\n");
}

static void play_current(void) {
    if (current == NULL) {
        printf("Playlist is empty. Add a song first.\n");
        return;
    }

    printf("Now playing: %s - %s\n", current->title, current->artist);
    printf("(Playback is simulated.)\n");
}

static void play_next(void) {
    if (current == NULL) {
        printf("Playlist is empty. Add a song first.\n");
        return;
    }

    current = current->next;
    play_current();
}

static void play_previous(void) {
    Song *temp;

    if (head == NULL || current == NULL) {
        printf("Playlist is empty. Add a song first.\n");
        return;
    }

   
    temp = current;
    while (temp->next != current) {
        temp = temp->next;
    }
    current = temp;
    play_current();
}

static void delete_song(void) {
    char title[TITLE_LEN];
    Song *temp;
    Song *prev;
    Song *target;

    if (head == NULL) {
        printf("Playlist is empty. Nothing to delete.\n");
        return;
    }

    read_line("Enter the exact song title to delete: ", title, sizeof(title));
    if (title[0] == '\0') {
        printf("Song title cannot be empty.\n");
        return;
    }

    target = find_song(title);
    if (target == NULL) {
        printf("Song not found.\n");
        return;
    }

    if (target->next == target) {
        free(target);
        head = NULL;
        current = NULL;
        printf("Song deleted successfully. Playlist is now empty.\n");
        return;
    }

    
    prev = target;
    while (prev->next != target) {
        prev = prev->next;
    }

    if (target == head) {
        head = target->next;
    }

    if (target == current) {
        current = target->next;
    }

    prev->next = target->next;
    free(target);
    printf("Song deleted successfully.\n");

    /* Keep current valid if it somehow became NULL. */
    if (current == NULL) {
        current = head;
    }

   
    temp = head;
    (void)temp;
}

static void search_song(void) {
    char title[TITLE_LEN];
    Song *result;

    if (head == NULL) {
        printf("Playlist is empty. Nothing to search.\n");
        return;
    }

    read_line("Enter song title to search: ", title, sizeof(title));
    result = find_song(title);

    if (result == NULL) {
        printf("Song not found.\n");
    } else {
        printf("Song found: %s - %s\n", result->title, result->artist);
    }
}

static void count_songs(void) {
    Song *temp;
    size_t count = 0;

    if (head != NULL) {
        temp = head;
        do {
            ++count;
            temp = temp->next;
        } while (temp != head);
    }

    printf("Total songs in playlist: %zu\n", count);
}

static void free_playlist(void) {
    Song *temp;
    Song *next_song;

    if (head == NULL) {
        return;
    }

    temp = head->next;
    while (temp != head) {
        next_song = temp->next;
        free(temp);
        temp = next_song;
    }
    free(head);
    head = NULL;
    current = NULL;
}

static int read_menu_choice(void) {
    char input[32];
    char *end;
    long choice;

    read_line("\nEnter your choice: ", input, sizeof(input));
    if (input[0] == '\0') {
        return -1;
    }

    choice = strtol(input, &end, 10);
    while (*end != '\0' && isspace((unsigned char)*end)) {
        ++end;
    }

    if (*end != '\0' || choice < 0 || choice > 8) {
        return -1;
    }
    return (int)choice;
}

int main(void) {
    int choice;

    printf("====================================\n");
    printf("       MUSIC PLAYLIST MANAGER       \n");
    printf("   Circular Singly Linked List      \n");
    printf("====================================\n");

    do {
        printf("\n----------- MENU -----------\n");
        printf("1. Add a song\n");
        printf("2. Delete a song by title\n");
        printf("3. Display playlist\n");
        printf("4. Play current song\n");
        printf("5. Play next song\n");
        printf("6. Play previous song\n");
        printf("7. Search for a song\n");
        printf("8. Count songs\n");
        printf("0. Exit\n");

        choice = read_menu_choice();

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                delete_song();
                break;
            case 3:
                display_playlist();
                break;
            case 4:
                play_current();
                break;
            case 5:
                play_next();
                break;
            case 6:
                play_previous();
                break;
            case 7:
                search_song();
                break;
            case 8:
                count_songs();
                break;
            case 0:
                free_playlist();
                printf("Playlist closed. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 0 to 8.\n");
        }
    } while (choice != 0);

    return 0;
}
