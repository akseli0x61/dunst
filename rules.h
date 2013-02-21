#pragma once

// {{{ INCLUDES
#include <glib.h>

#include "dunst.h"
#include "notification.h"
// }}}

// {{{ STRUCTS
typedef struct _rule_t {
        char *name;
        /* filters */
        char *appname;
        char *summary;
        char *body;
        char *icon;

        /* actions */
        int timeout;
        int urgency;
        char *fg;
        char *bg;
        const char *format;
        const char *script;
} rule_t;
// }}}

// {{{ GLOBALS
extern GSList *rules;
// }}}

// {{{ FUNCTIONS
void rule_init(rule_t *r);
void rule_apply(rule_t *r, notification *n);
void rule_apply_all(notification *n);
bool rule_matches_notification(rule_t *r, notification *n);
// }}}