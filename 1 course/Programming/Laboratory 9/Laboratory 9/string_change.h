//
//  string_change.h
//  Laboratory 9
//
//  Created by Даниил on 20/02/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#ifndef string_change_h
#define string_change_h

/**
 Выполняет удаление слов, подходящих по длине, в строке.

 @param string Строка, в которой будет выполнятся удаление слов.
 @param min_word_length Минимальная длина слова, которое будет удалено.
 */
void str_remove_word_more_than_or_equal(char *string,
                                        const unsigned int min_word_length);

/**
 Выполняет удаление самого последнего символа перехода на новую строку.

 @param string Строка, в которой необходимо удалить символ.
 */
void str_remove_final_line_break(char *string);

#endif /* string_change_h */
