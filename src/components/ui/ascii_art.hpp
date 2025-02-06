#include <string>

namespace asciiArt {

class AsciiArtwork{
  public:
    std::string_view artwork;
    int width = 0, height = 0;
  
    AsciiArtwork (std::string_view a) {
      artwork = a;

      int max = 0, curr = 0;
      for (char c : a) {
        if (c == '\n') {
            if (max < curr) max = curr; 
            curr = 0;
        } else curr++;
        height++;
      }
      width = max;
    }
    AsciiArtwork(){
      std::string_view artwork = (std::string_view{ 
R"(Ascii
Not Loaded!)"});
    };
};

const AsciiArtwork logo = {(std::string_view{ 
//the first line alignement must be messed up. WEAKNESS OF THE FLESH WILL NOT DISPLEASE THE MACHINE GODS MUHAHAHAHAHAAH
    R"(                 ...  ..      . %%#+=:..
             ...+@@-. ..@@.     @.*. ..*=
            .@:..+%.. .@@#.@+. .:-@%.@@.%..
              .=@..@@@.+@@%@.%- .@.@@@@@.%.
        .@@@@@:...@..@@@@@+.@@.=--.%@@@@%.@.
      .%+.@@@*..%%@%#.@*..*@@@@@@@@@-@%.@@@.-@*..
    .:@.  .-@@@@@*.@@@@@@@@@..........:@@@@@@%#.%%..
  ..%..%@@@+@@..@@@@@@@..@+ .#@%-....@..  #%.#@@@%.%.
 .@-...*%@@%@.@.. .@@.  .@@. .  .:%@%-.  .@.   @@@@%.@+.
 ......-%@.@@-:.@-.@..+@@@@@@@@@@@@@@@@@@..    =@...@%.@.
     ..:@.@@%@.. .@@@@#..           .@@@@@@@@@@@..  ..@.#+.
 .@@...*@%@+.@@@@@@#..%@@@@..       *@.@@@@...@%@@:.  .@*#..
@..@@@@@.-%. .%@@@@@@:....:===-.....@#.%%:....@@..@@@. .@.@ .
@.  .%@@.@.    ..@@@@@@@@@@%#++#@@@@@@@@@@::@@:..:@.@@..%.@..
@..:@%@%@%   :@@%.    .@..@%-::+@%@@%+...@@@@@%::%.#:%@@.+:.
@.@-.@.@@#   @@@%.    :@.@               -@@@:.+.@..%-..@
@..@.%.@@%.   ...   .@@@%..@%@..            ....%.=@%%..
@@:#:=%%.@@@@@@@@@@@@%..%@@@%@=..@%-.
%.@.@@@@.@@..=#%#=..     %@:-#@@@@%..%%..
 @... .@%.@..  ..%@%.    @@.  .:%.@@@%..@@.
 .@...@@+.-%-   .@@@. .@%..@@..@@ . .:@%%.-@..
  .@:.@.+%%.#%@*...-@@@..    .@@.      .@@%.##.
   .%:.%...:@@..-@@@@@@@%@@@%@#..      . .%@..@.
    .@@.     . .*@@...      ..:@@@#   .@@@%@@#.@.
             .@..@@=..@@@#...   ..%@@. @@ .-@@@.%.
           .@.%@..@.%@...@@*-+@%+.. %@.%#   .@@:.@.
          *:.@:..=@%..%..       ..%..*@+.    .@@.@..
         +..@..%.@@ :*             .%.#@     .@@:.*
        .@.@@:#@@@..#               ::.@+  .%..@% @
       .%.%@ @@.@%.@.               .@ @@..@@@.%@ @
       .@.%= ...@%.@.                @ %%%@..%%%@ @
       .@.@@@....%..:               .#.@@..#..@@:.*
       .@.%@.@@+.@@.%..            .%.%% .@@@.@@.%..
        :# @....%@@@..@.        ..%+.%@.  ....%:.%.
         @.:@.=%  .@@*..@%.....*@..-@%.     .@@.%.
         .@.:@% .@@..@@@*.......=@@%       .@%.@.
         ..@..@*.@@..%...@@@@@@#..        .@..@.
            *@.=@.. -@..@@..@# .@@@%    .@*.@=.
             .@@. @%#@..@%. :@:.:@%. .@@..%% .
              ..*@...@%@:.....@@#.%@@..=@=.
                 ..+@@:............+@%:
                       ..%%%%%%@*..
                         '''''''''
)"})};
const AsciiArtwork title = {(std::string_view{
    R"( ____    __                   __
/\  _`\ /\ \                 /\ \
\ \,\L\_\ \ \___      __     \_\ \    ___   __  __  __  _ __   __  __    ___
 \/_\__ \\ \  _ `\  /'__`\   /'_` \  / __`\/\ \/\ \/\ \/\`'__\/\ \/\ \ /' _ `\
   /\ \L\ \ \ \ \ \/\ \L\.\_/\ \L\ \/\ \L\ \ \ \_/ \_/ \ \ \/ \ \ \_\ \/\ \/\ \
   \ `\____\ \_\ \_\ \__/.\_\ \___,_\ \____/\ \___x___/'\ \_\  \ \____/\ \_\ \_\
    \/_____/\/_/\/_/\/__/\/_/\/__,_ /\/___/  \/__//__/   \/_/   \/___/  \/_/\/_/
 ______      __                         __
/\  _  \    /\ \                       /\ \__
\ \ \L\ \   \_\ \  __  __     __    ___\ \ ,_\  __  __  _ __    __    __
 \ \  __ \  /'_` \/\ \/\ \  /'__`\/' _ `\ \ \/ /\ \/\ \/\`'__\/'__`\ /\_\
  \ \ \/\ \/\ \L\ \ \ \_/ |/\  __//\ \/\ \ \ \_\ \ \_\ \ \ \//\  __/ \/_/_
   \ \_\ \_\ \___,_\ \___/ \ \____\ \_\ \_\ \__\\ \____/\ \_\\ \____\  /\_\
    \/_/\/_/\/__,_ /\/__/   \/____/\/_/\/_/\/__/ \/___/  \/_/ \/____/  \/_/
                                            ______                          _____
                                           /\__  _\                        /\  __`\
                                           \/_/\ \/    __   _ __    ___ ___\ \ \/\ \   __  _
                                              \ \ \  /'__`\/\`'__\/' __` __`\ \ \ \ \ /\ \/'\
                                               \ \ \/\  __/\ \ \/ /\ \/\ \/\ \ \ \_\ \\/>  </
                                                \ \_\ \____\\ \_\ \ \_\ \_\ \_\ \_____\/\_/\_\
                                                 \/_/\/____/ \/_/  \/_/\/_/\/_/\/_____/\//\/_/
)"})};

} //namespace end