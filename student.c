#include <assert.h>
#include "student.h"

static int student_gpa_comparator(struct ll_node *first, struct ll_node *second) {
    double first_gpa = LL_ENTRY(first, struct student, node)->gpa;
    double second_gpa = LL_ENTRY(second, struct student, node)->gpa;

    if (first_gpa < second_gpa) {
        return -1;
    } else if (first_gpa > second_gpa) {
        return 1;
    } else {
        return 0;
    }
}

struct student *student_worst_performer(struct student *list) {
    assert(list != NULL);
    struct ll_node *worst = ll_min(&(list->node), student_gpa_comparator);
    return LL_ENTRY(worst, struct student, node);
}

struct student *student_valedictorian(struct student *list) {
    assert(list != NULL);
    struct ll_node *best = ll_max(&(list->node), student_gpa_comparator);
    return LL_ENTRY(best, struct student, node);
}

static bool student_on_honour_roll(struct ll_node *s) {
    return LL_ENTRY(s, struct student, node)->gpa >= 3.50;
}

struct student *student_honour_roll(struct student *list) {
    assert(list != NULL);
    struct ll_node *filtered_list = ll_filter(&(list->node), student_on_honour_roll);
    return filtered_list != NULL ? LL_ENTRY(filtered_list, struct student, node) : NULL;
}
