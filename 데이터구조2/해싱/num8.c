int hash_lp_delete(element item) {
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(hash_table[i])) {
        if (equal(item, hash_table[i])) {
            hash_table[i].key[0] = '\0';
            printf("%s�� �ؽ� ���̺� %d �ε������� ������!\n", item.key, i);
            return EXIT_SUCCESS;
        }
        else if ((i + 1) % TABLE_SIZE == hash_value) {
            printf("ã�� ���� ���̺� ����\n");
            return EXIT_SUCCESS;
        }
    }
    printf("ã�� ���� ���̺� ����\n");
    return EXIT_SUCCESS;
}