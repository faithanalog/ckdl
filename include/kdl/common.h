#ifndef KDL_COMMON_H_
#define KDL_COMMON_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef size_t (*kdl_read_func)(void *user_data, char *buf, size_t bufsize);

struct _kdl_str {
    char const *data;
    size_t len;
};
typedef struct _kdl_str kdl_str;

struct _kdl_owned_string {
    char *data;
    size_t len;
};
typedef struct _kdl_owned_string kdl_owned_string;

inline kdl_str kdl_borrow_str(kdl_owned_string const *str)
{
    return (kdl_str){ str->data, str->len };
}

kdl_owned_string kdl_clone_str(kdl_str const *s);
void kdl_free_string(kdl_owned_string *s);
kdl_owned_string kdl_escape(kdl_str const *s);
kdl_owned_string kdl_unescape(kdl_str const *s);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // KDL_COMMON_H_