module;

export module utilities; 

import handling_characters;
import handling_c_strings;
import handling_std_strings;
import string_literals;
import string_views;


export void handling_characters_demo(){

    handling_characters::is_al_num();
    handling_characters::is_alphabetic();
    handling_characters::is_blank();
    handling_characters::is_upercase();
    handling_characters::is_digit();
    handling_characters::change_to_lowercase();

}


export void handling_c_strings_demo(){

    handling_c_strings::cstring_strlen();
    handling_c_strings::cstring_strcmp();
    handling_c_strings::cstring_strncmp();

}

export void handling_std_strings_demo(){

    //handling_std_strings::std_string_declaration();
    handling_std_strings::std_string_concatenation();

}


export void string_literals_demo(){

    //string_literals::escape_sequences();
    string_literals::raw_string_literals();

}


export void string_views_demo(){

    //string_views::the_problem();
    //string_views::the_solution();
    //string_views::string_view_construction();
    //string_views::std_string_view_visualizes_original_string();
    //string_views::std_string_view_change_view_window();
    //string_views::std_string_view_lifetime();
    //string_views::std_string_view_data();
    string_views::std_string_view_behaviors();

}