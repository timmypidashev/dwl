#include <stdbool.h>
#include <string.h>

// Remove the tags definition as it's already in config.h
// static char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

// Use LENGTH macro if it's defined in config.h, otherwise define TAGCOUNT
#ifndef LENGTH
#define TAGCOUNT (sizeof(tags) / sizeof(tags[0]))
#else
#define TAGCOUNT LENGTH(tags)
#endif

void
shiftview(const Arg *arg)
{
    Arg a;
    Client *c;
    bool visible = false;
    int i = arg->i;
    int count = 0;
    unsigned int nextseltags, curseltags = selmon->tagset[selmon->seltags];

    do {
        if (i > 0) // left circular shift
            nextseltags = ((curseltags << i) | (curseltags >> (TAGCOUNT - i))) & ((1U << TAGCOUNT) - 1);
        else // right circular shift
            nextseltags = ((curseltags >> (-i)) | (curseltags << (TAGCOUNT + i))) & ((1U << TAGCOUNT) - 1);

        // Check if the tag is visible
        wl_list_for_each(c, &clients, link) {
            if (c->mon == selmon && nextseltags & c->tags) {
                visible = true;
                break;
            }
        }
        i += arg->i;
    } while (!visible && ++count < (int)TAGCOUNT);

    if (count < (int)TAGCOUNT) {
        a.i = nextseltags;
        view(&a);
    }
}
