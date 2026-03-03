#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void run_test(int fd, const char *test_name)
{
    char *line;
    int count = 1;

    printf("========== %s ==========\n", test_name);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", count++, line);
        // Eğer satır \n ile bitmiyorsa (EOF durumu), formatı bozmamak için manuel alt satıra geç
        if (line[f_strlen(line) - 1] != '\n')
            printf("\n");
        free(line);
    }
    printf("-> EOF veya Hata (NULL döndü)\n\n");
}

int main(void)
{
    int fd;

    // Test 1: Normal dosya okuması (Son satırda \n yok)
    fd = open("test_normal.txt", O_RDONLY);
    run_test(fd, "Test 1: Normal Dosya");
    close(fd);

    // Test 2: Boş dosya okuması
    fd = open("test_empty.txt", O_RDONLY);
    run_test(fd, "Test 2: Boş Dosya");
    close(fd);

    // Test 3: Sadece newline (\n) içeren dosya
    fd = open("test_newlines.txt", O_RDONLY);
    run_test(fd, "Test 3: Sadece Newlines");
    close(fd);

    // Test 4: Tek satır ve \n içermeyen dosya
    fd = open("test_single.txt", O_RDONLY);
    run_test(fd, "Test 4: Tek Satir (No Newline)");
    close(fd);

    // Test 5: Geçersiz File Descriptor (Hata Yönetimi)
    run_test(-1, "Test 5: Geçersiz FD (-1)");

    // Test 6: Kapalı File Descriptor
    fd = open("test_normal.txt", O_RDONLY);
    close(fd);
    run_test(fd, "Test 6: Kapatilmis FD");

    return (0);
}