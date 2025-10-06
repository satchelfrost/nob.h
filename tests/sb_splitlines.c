#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

int main()
{
    // test mixes both \r\n and \n for "lines"
    String_Builder sb = {0};
    sb_appendf(&sb, "one\r\n");
    sb_appendf(&sb, "two\n");
    sb_appendf(&sb, "three\r\n");
    sb_appendf(&sb, "four\n");
    sb_appendf(&sb, "five\r\n");

    String_Builders sbs = sb_splitlines(sb);

    printf("line count: %zu\n", sbs.count);
    for (size_t i = 0; i < sbs.count; i++) {
        sb_append_null(&sbs.items[i]);
        printf("line %zu: \"%s\", char count: %zu\n", i+1, sbs.items[i].items, sbs.items[i].count-1);
    }

    sb_free(sb);
    sbs_free(sbs);

    return 0;
}
