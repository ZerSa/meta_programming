//
// Created by zersa on 10/29/19.
//

#ifndef SECOND_TASK_GETINDEXOF_H
#define SECOND_TASK_GETINDEXOF_H

template< class T, class U >
struct Tuple {
    typedef T head;
    typedef U tail;
};

struct NullType {

};


template <class T, class U, class S>
struct GetIndexOfRec {
    int operator()() {
        if (GetIndexOfRec < typename U::head, typename U::tail, S > ()() < 0)
            return -1;
        return GetIndexOfRec <typename U::head, typename U::tail, S >()() + 1;
    }
};

//дошли до конца и не нашли совпадений, возвращаем -1
template <class T, class S>
struct GetIndexOfRec< T, NullType, S > {
    int operator()() {
        return -1;
    }
};

//дошли до конца и нашли совпадение
template < class S >
struct GetIndexOfRec< S, NullType, S > {
    int operator()() {
        return 0;
    }
};

//нашли совпадение с "головой"
template < class T, class S >
struct GetIndexOfRec< S, T, S > {
    int operator()() {
        return 0;
    }
};

template < class T, class S >
struct GetIndexOf {
    int operator()() {
        return GetIndexOfRec < typename T::head, typename T::tail, S > ()();
    }
};


#endif //SECOND_TASK_GETINDEXOF_H


