int hash_lp_delete(element item) {
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(hash_table[i])) {
        if (equal(item, hash_table[i])) {
            hash_table[i].key[0] = '\0';
            printf("%s를 해쉬 테이블 %d 인덱스에서 지웠음!\n", item.key, i);
            return EXIT_SUCCESS;
        }
        else if ((i + 1) % TABLE_SIZE == hash_value) {
            printf("찾는 값이 테이블에 없음\n");
            return EXIT_SUCCESS;
        }
    }
    printf("찾는 값이 테이블에 없음\n");
    return EXIT_SUCCESS;
}