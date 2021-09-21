/*!
 * \file searching.cpp
 * Binary search, Linear search, Upper bound, lower bound implementation for an array of integers.
 * \author Selan R. dos Santos
 * \date June 17th, 2021.
 */

#include "searching.h"

namespace sa {

    /*!
     * Performs a **linear search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lsearch( value_type * first, value_type * last, value_type value )
    {
        value_type* find{last};

        for (value_type* i{first}; i < last; i++) {
            if (*i == value) {
                find = i;
            }
        }

        return find;
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch( value_type * first, value_type * last, value_type value )
    {
        value_type* find{last};
        value_type* first_bs{first};
        value_type* last_bs{last};

        while (first_bs < last_bs) {
            value_type* middle = first_bs + (last_bs - first_bs) / 2;

            if (*(middle) == value) {
                find = middle;
                break;
            }

            else if (*(middle) < value) {
                first_bs = middle + 1;
            }

            else if (*(middle) > value) {
                last_bs = middle;
            }
        }

        return find;
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch_rec( value_type * first, value_type * last, value_type value )
    {
        if (first < last) {
            value_type* middle = first + (last - first) / 2;

            if (*(middle) == value) {
                return middle;
            }

            else if (*(middle) < value) {
                return bsearch_rec(middle+1, last, value);
            }

            else if (*(middle) > value) {
                return bsearch_rec(first, middle, value);
            }
        }

        return nullptr;
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * This function is a assistant to the recursive binary search. It serves to preserve the value of the pointer last in cases where we don't find the element in the array.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch_rec_aux( value_type * first, value_type * last, value_type value )
    {
        value_type* resp = bsearch_rec(first, last, value);

        if (resp == nullptr) {
            return last;
        }
        else {
            return resp;
        }
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _not less_  than (i.e. greater or equal to) `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lbound( value_type * first, value_type * last, value_type value )
    {
        value_type* find{last};
        value_type* first_bs{first};
        value_type* last_bs{last};

        while (first_bs < last_bs) {
            value_type* middle = first_bs + (last_bs - first_bs) / 2;

            if (*(middle) >= value) {
                find = middle;
                last_bs = middle;
            }

            else {
                first_bs = middle + 1;
            }
        }

        return find;
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _greater_  than `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * ubound( value_type * first, value_type * last, value_type value )
    {
        value_type* find{last};
        value_type* first_bs{first};
        value_type* last_bs{last};

        while (first_bs < last_bs) {
            value_type* middle = first_bs + (last_bs - first_bs) / 2;

            if (*(middle) > value) {
                find = middle;
                last_bs = middle;
            }

            else {
                first_bs = middle + 1;
            }
        }

        return find;
        return first; // STUB
    }
}

