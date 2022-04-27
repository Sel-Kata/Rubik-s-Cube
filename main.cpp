#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

// 1 - Белый, 2 - Жёлтый, 3 - Розовый, 4 - Зелёный, 5 - Ораньжевый, 6 - Синий

class Cube{
private:
    int front_[3][3];
    int back_[3][3];
    int right_[3][3];
    int left_[3][3];
    int up_[3][3];
    int down_[3][3];

public:
    int get_front(int i, int j){
        return front_[i][j];
    }
    int get_right(int i, int j){
        return right_[i][j];
    }
    int get_left(int i, int j){
        return left_[i][j];
    }
    int get_back(int i, int j){
        return back_[i][j];
    }
    int get_down(int i, int j){
        return down_[i][j];
    }
    int get_up(int i, int j){
        return up_[i][j];
    }

    void set_front(int i, int j, int value){
        front_[i][j] = value;
    }
    void set_right(int i, int j, int value){
        right_[i][j] = value;
    }
    void set_back(int i, int j, int value){
        back_[i][j] = value;
    }
    void set_up(int i, int j, int value){
        up_[i][j] = value;
    }
    void set_down(int i, int j, int value){
        down_[i][j] = value;
    }
    void set_left(int i, int j, int value){
        left_[i][j] = value;
    }

    bool operator == (const Cube& other){
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                if (this->front_[i][j] != other.front_[i][j])
                    return false;
                if (this->back_[i][j] != other.back_[i][j])
                    return false;
                if (this->right_[i][j] != other.right_[i][j])
                    return false;
                if (this->left_[i][j] != other.left_[i][j])
                    return false;
                if (this->up_[i][j] != other.up_[i][j])
                    return false;
                if (this->down_[i][j] != other.down_[i][j])
                    return false;
            }
        }
        return true;
    }

    bool operator != (const Cube& other){
        return !(this->operator==(other));
    }

    Cube& operator = (const Cube& other){
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                set_front(i, j, other.front_[i][j]);
                set_back(i, j, other.back_[i][j]);
                set_right(i, j, other.right_[i][j]);
                set_left(i, j, other.left_[i][j]);
                set_up(i, j, other.up_[i][j]);
                set_down(i, j, other.down_[i][j]);
            }
        }
        return *this;
    }

    Cube(){
        int front[3][3] = {{6, 6, 6}, {6, 6, 6}, {6, 6, 6}};
        int back[3][3] = {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}};
        int right[3][3] = {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}};
        int left[3][3] = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};
        int up[3][3] = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
        int down[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                set_front(i, j, front[i][j]);
                set_back(i, j, back[i][j]);
                set_right(i, j, right[i][j]);
                set_left(i, j, left[i][j]);
                set_up(i, j, up[i][j]);
                set_down(i, j, down[i][j]);
            }
        }
    }

    Cube(int front[3][3], int back[3][3], int right[3][3], int left[3][3], int up[3][3], int down[3][3]){
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                set_front(i, j, front[i][j]);
                set_back(i, j, back[i][j]);
                set_right(i, j, right[i][j]);
                set_left(i, j, left[i][j]);
                set_up(i, j, up[i][j]);
                set_down(i, j, down[i][j]);
            }
        }
    }

    void right_rotation_up(){
        int up1[3], up2[3], back1[3], back2[3], down1[3], down2[3], front1[3], front2[3];
        
        for (int i = 0; i < 3; ++i){
            up1[i] = get_up(i, 2);
            back1[i] = get_back(i, 2);
            down1[i] = get_down(i, 2);
            front1[i] = get_front(i, 2);

            up2[i] = get_right(0, i);
            back2[i] = get_right(i, 2);
            down2[i] = get_right(2, i);
            front2[i] = get_right(i, 0);
        }
        int front3[3], back3[3];
        int counter = 2;
        for (int i = 0; i < 3; i++)
        {
            front3[i] = front2[counter];
            back3[i] = back2[counter];
            counter--;
        }

        for (int i = 0; i < 3; ++i){
            set_up(i, 2, front1[i]);
            set_back(i, 2, up1[i]);
            set_down(i, 2, back1[i]);
            set_front(i , 2, down1[i]);

            set_right(0, i, front3[i]);///
            set_right(i, 0, down2[i]);
            set_right(2, i, back3[i]);///
            set_right(i, 2, up2[i]);
        }
    }
    void right_rotation_down(){
        this->right_rotation_up();
        this->right_rotation_up();
        this->right_rotation_up();
    }

    void left_rotation_up(){
        int up1[3], up2[3], back1[3], back2[3], down1[3], down2[3], front1[3], front2[3];

        for (int i = 0; i < 3; ++i){
            up1[i] = get_up(i, 0);
            back1[i] = get_back(i, 0);
            down1[i] = get_down(i, 0);
            front1[i] = get_front(i, 0);

            up2[i] = get_left(0, i);//
            back2[i] = get_left(i, 0);
            down2[i] = get_left(2, i);//
            front2[i] = get_left(i, 2);
        }
        int up3[3], down3[3];
        int counter = 2;

        for (int i = 0; i < 3; i++)
        {
            up3[i] = up2[counter];
            down3[i] = down2[counter];
            counter--;
        }

        for (int i = 0; i < 3; ++i){
            set_up(i, 0, front1[i]);
            set_back(i, 0, up1[i]);
            set_down(i, 0, back1[i]);
            set_front(i , 0, down1[i]);

            set_left(0, i, front2[i]);
            set_left(i, 0, up3[i]);
            set_left(2, i, back2[i]);
            set_left(i, 2, down3[i]);
        }
    }
    void left_rotation_down(){
        this->left_rotation_up();
        this->left_rotation_up();
        this->left_rotation_up();
    }

    void up_rotation_right(){
        int front1[3], front2[3], right1[3], right2[3], back1[3], back2[3], left1[3], left2[3];
        for (int i = 0; i < 3; ++i){
            front1[i] = get_front(0, i);
            right1[i] = get_right(0, i);
            back1[i] = get_back(0, i);
            left1[i] = get_left(0, i);

            front2[i] = get_up(2, i);
            right2[i] = get_up(i, 2);
            back2[i] = get_up(0, i);
            left2[i] = get_up(i, 0);
        }

        int front3[3], right3[3], back3[3], left3[3];
        int counter = 2;

        for (int i = 0; i < 3; i++)
        {
            front3[i] = front2[counter];
            right3[i] = right2[counter];
            back3[i] = back2[counter];
            left3[i] = left2[counter];
            counter--;
        }
        for (int i = 0; i < 3; ++i){
            set_right(0, i, front1[i]);
            set_back(0, i, right1[i]);
            set_left(0, i, back1[i]);
            set_front(0, i, left1[i]);

            set_up(i, 0, back3[i]);////
            set_up(2, i, left2[i]);
            set_up(i, 2, front3[i]);
            set_up(0, i, right2[i]);
        }
    }///
    void up_rotation_left(){
        this->up_rotation_right();
        this->up_rotation_right();
        this->up_rotation_right();
    }

    void down_rotation_right(){
        int front1[3], front2[3], right1[3], right2[3], back1[3], back2[3], left1[3], left2[3];

        for (int i = 0; i < 3; ++i){
            front1[i] = get_front(2, i);
            right1[i] = get_right(2, i);
            back1[i] = get_back(2, i);
            left1[i] = get_left(2, i);

            front2[i] = get_down(0, i);
            right2[i] = get_down(i, 2);
            back2[i] = get_down(2, i);
            left2[i] = get_down(i, 0);
        }
        
        int front3[3], right3[3], back3[3], left3[3];
        int counter = 2;

        for (int i = 0; i < 3; i++)
        {
            front3[i] = front2[counter];
            right3[i] = right2[counter];
            back3[i] = back2[counter];
            left3[i] = left2[counter];
            counter--;
        }

        for (int i = 0; i < 3; ++i){
            set_right(2, i, front1[i]);
            set_back(2, i, right1[i]);
            set_left(2, i, back1[i]);
            set_front(2, i, left1[i]);

            set_down(0, i, left3[i]);
            set_down(i, 2, front2[i]);
            set_down(2, i, right3[i]);
            set_down(i, 0, back2[i]);
        }
    }
    void down_rotation_left(){
        this->down_rotation_right();
        this->down_rotation_right();
        this->down_rotation_right();
    }

    void front_rotation_right(){
        int up1[3], up2[3], right1[3], right2[3], down1[3], down2[3], left1[3], left2[3];

        for (int i = 0; i < 3; ++i){
            up1[i] = get_up(2, i);
            right1[i] = get_right(i, 0);
            down1[i] = get_down(0, i);
            left1[i] = get_left(i, 2);

            up2[i] = get_front(0, i);
            right2[i] = get_front(i, 2);
            down2[i] = get_front(2, i);
            left2[i] = get_front(i, 0);
        }

        int left3[3], right3[3];
        int counter = 2;
        for (int i = 0; i < 3; i++)
        {
            left3[i] = left2[counter];
            right3[i] = right2[counter];
            counter--;
        }

        for (int i = 0; i < 3; ++i){
            set_up(2, i, left1[i]);
            set_right(i, 0, up1[i]);
            set_down(0, i, right1[i]);
            set_left(i, 2, down1[i]);

            set_front(0, i, left3[i]);
            set_front(i, 2, up2[i]);
            set_front(2, i, right3[i]);
            set_front(i, 0, down2[i]);
        }
    }
    void front_rotation_left(){
        this->front_rotation_right();
        this->front_rotation_right();
        this->front_rotation_right();
    }

    void back_rotation_right(){
        int up1[3], up2[3], right1[3], right2[3], down1[3], down2[3], left1[3], left2[3];

        for (int i = 0; i < 3; ++i){
            up1[i] = get_up(0, i);
            right1[i] = get_right(i, 2);
            down1[i] = get_down(2, i);
            left1[i] = get_left(i, 0);

            up2[i] = get_back(0, i);
            right2[i] = get_back(i, 0);
            down2[i] = get_back(2, i);
            left2[i] = get_back(i, 2);
        }

        int up3[3], down3[3];
        int counter = 2;

        for (int i = 0; i < 3; i++)
        {
            up3[i] = up2[counter];
            down3[i] = down2[counter];
            counter--;
        }

        for (int i = 0; i < 3; ++i){
            set_up(0, i, left1[i]);
            set_right(i, 2, up1[i]);
            set_down(2, i, right1[i]);
            set_left(i, 0, down1[i]);

            set_back(0, i, left2[i]);
            set_back(i, 0, up3[i]);
            set_back(2, i, right2[i]);
            set_back(i, 2, down3[i]);
        }
    }
    void back_rotation_left(){
        this->back_rotation_right();
        this->back_rotation_right();
        this->back_rotation_right();
    }
    
    
    bool side_completed(int side[3][3]){
        for(int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                if (side[i][j] != side[1][1])
                    return false;
            }
        }
        return true;
    }
    bool cube_is_completed(){
        bool rez = side_completed(front_);
        if (rez == false)
            return false;
        rez = side_completed(back_);
        if (rez == false)
            return false;
        rez = side_completed(right_);
        if (rez == false)
            return false;
        rez = side_completed(left_);
        if (rez == false)
            return false;
        rez = side_completed(up_);
        if (rez == false)
            return false;
        rez = side_completed(down_);
        if (rez == false)
            return false;
        return true;
    }
    

    void random_generation(){
        int run = 5;
        int number_rotate = 0;
        for (int i = 0; i < run; i++){
            number_rotate = (rand() * 100) % 12;
            switch (number_rotate){
                case 0:
                    this->up_rotation_left();
                    break;
                case 1:
                    this->left_rotation_up();
                    break;
                case 2:
                    this->down_rotation_right();
                    break;
                case 3:
                    this->down_rotation_left();
                    break;
                case 4:
                    this->back_rotation_right();
                    break;
                case 5:
                    this->up_rotation_right();
                    break;
                case 6:
                    this->left_rotation_down();
                    break;
                case 7:
                    this->right_rotation_up();
                    break;
                case 8:
                    this->right_rotation_down();
                    break;
                case 9:
                    this->back_rotation_left();
                    break;
                case 10:
                    this->front_rotation_left();
                    break;
                case 11:
                    this->front_rotation_right();
            }
        }
    }
};

std::pair<long long, long long> numbers;

bool is_equal(std::vector<Cube> first, std::vector<Cube> second)
{
    for (int i = 0; i < first.size(); i++)
    {
        for (int j = 0; j < second.size(); j++)
        {
            if (first[i] == second[j])
            {
                numbers.first = i;
                numbers.second = j;
                return true;
            }
        }
    }
    return false;
}

std::string getting_ways(Cube cub){
    std::string answer;
    std::queue<Cube> the_first_queue;
    std::queue<Cube> the_second_queue;

    Cube temp;

    if (temp == cub)
        return answer;

    std::vector<Cube> the_first_set;
    std::vector<std::string> the_first_set_way;
    std::vector<Cube> the_second_set;
    std::vector<std::string> the_second_set_way;

    the_first_queue.push(cub);
    the_second_queue.push(temp);
    the_first_set.push_back(cub);
    the_second_set.push_back(temp);

    bool flag = true;

    Cube rotate_cube;
    int counter = 0;
    while (flag)
    {
        rotate_cube = the_first_queue.front();
        the_first_queue.pop();
        the_first_set_way.push_back("");
        
        rotate_cube.right_rotation_up();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=r_r_u=");
        rotate_cube.right_rotation_down();
        rotate_cube.right_rotation_down();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=r_r_d=");
        rotate_cube.right_rotation_up();

        rotate_cube.left_rotation_up();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=l_r_u=");
        rotate_cube.left_rotation_down();
        rotate_cube.left_rotation_down();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=l_r_d=");
        rotate_cube.left_rotation_up();

        rotate_cube.up_rotation_right();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=u_r_r=");
        rotate_cube.up_rotation_left();
        rotate_cube.up_rotation_left();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=u_r_l=");
        rotate_cube.up_rotation_right();

        rotate_cube.down_rotation_right();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=d_r_r=");
        rotate_cube.down_rotation_left();
        rotate_cube.down_rotation_left();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=d_r_l=");
        rotate_cube.down_rotation_right();

        rotate_cube.front_rotation_right();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=f_r_r=");
        rotate_cube.front_rotation_left();
        rotate_cube.front_rotation_left();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=f_r_l=");
        rotate_cube.front_rotation_right();

        rotate_cube.back_rotation_left();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=b_r_l=");
        rotate_cube.back_rotation_right();
        rotate_cube.back_rotation_right();
        the_first_queue.push(rotate_cube);
        the_first_set.push_back(rotate_cube);
        the_first_set_way.push_back(the_first_set_way[counter] + "=b_r_r=");
        rotate_cube.back_rotation_left();

        if (is_equal(the_first_set, the_second_set))
            flag = false;

        if (flag){
            rotate_cube = the_second_queue.front();
            the_second_queue.pop();
            the_second_set_way.push_back("");

            rotate_cube.right_rotation_up();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=r_r_d=");
            rotate_cube.right_rotation_down();
            rotate_cube.right_rotation_down();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=r_r_u=");
            rotate_cube.right_rotation_up();
            
            rotate_cube.left_rotation_up();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=l_r_d=");
            rotate_cube.left_rotation_down();
            rotate_cube.left_rotation_down();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=l_r_u=");
            rotate_cube.left_rotation_up();

            rotate_cube.up_rotation_right();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=u_r_l=");
            rotate_cube.up_rotation_left();
            rotate_cube.up_rotation_left();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=u_r_r=");
            rotate_cube.up_rotation_right();

            rotate_cube.down_rotation_right();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=d_r_l=");
            rotate_cube.down_rotation_left();
            rotate_cube.down_rotation_left();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=d_r_r=");
            rotate_cube.down_rotation_right();

            rotate_cube.front_rotation_right();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=f_r_l=");
            rotate_cube.front_rotation_left();
            rotate_cube.front_rotation_left();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=f_r_r=");
            rotate_cube.front_rotation_right();

            rotate_cube.back_rotation_left();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=b_r_r=");
            rotate_cube.back_rotation_right();
            rotate_cube.back_rotation_right();
            the_second_queue.push(rotate_cube);
            the_second_set.push_back(rotate_cube);
            the_second_set_way.push_back(the_second_set_way[counter] + "=b_r_l=");
            rotate_cube.back_rotation_left();

            if (is_equal(the_first_set, the_second_set))
                flag = false;
        }

        counter++;
    }

    answer = the_first_set_way[numbers.first] + the_second_set_way[numbers.second];

    return answer;
}

void assembling(Cube& cub){//сборка
    std::string way;
    way = getting_ways(cub);

    if (way.empty())
    {
        std::cout << "cube is normal\n";
        return;
    }

    std::cout << way << std::endl;
    
    for (int i = 0; i < way.size(); i += 7)
    {
        switch (way[i + 1]) {
            case 'r':
                if (way[i + 5] == 'u')
                    cub.right_rotation_up();
                else
                    cub.right_rotation_down();
                break;
            case 'l':
            {
                if (way[i + 5] == 'u')
                    cub.left_rotation_up();
                else
                    cub.left_rotation_down();
                break;
            }
            case 'u':
                if (way[i + 5] == 'r')
                    cub.up_rotation_right();
                else
                    cub.up_rotation_left();
                break;
            case 'd':
                if (way[i + 5] == 'r')
                    cub.down_rotation_right();
                else
                    cub.down_rotation_left();
                break;
            case 'f':
                if (way[i + 5] == 'r')
                    cub.front_rotation_right();
                else
                    cub.front_rotation_left();
                break;
            case 'b':
                if (way[i + 5] == 'l')
                    cub.back_rotation_left();
                else
                    cub.back_rotation_right();
                break;
        }
    }
}

std::ostream& operator<< (std::ostream& stream, Cube cub){
    for (int i = 0; i < 3; ++i){
        stream << "\t    ";
        for (int j = 0; j < 3; ++j)
            stream << cub.get_up(i, j) << " ";
        stream << "\n";
    }
    for (int j = 0; j < 3; ++j){
        for (int i = 0; i < 3; ++i){
            stream << cub.get_back(j, i) << " ";
        }
        for (int i = 0; i < 3; ++i){
            stream << cub.get_left(j, i) << " ";
        }
        for (int i = 0; i < 3; ++i){
            stream << cub.get_front(j, i) << " ";
        }
        for (int i = 0; i < 3; ++i){
            stream << cub.get_right(j, i) << " ";
        }
        stream << "\n";
    }
    for (int i = 0; i < 3; ++i){
        stream << "\t    ";
        for (int j = 0; j < 3; ++j)
            stream << cub.get_down(i, j) << " ";
        stream << "\n";
    }
    return stream;
}

int main(){
    std::cout << "\n\n";

    int front[3][3] = {{6, 6, 6}, {6, 6, 6}, {6, 6, 6}};
    int back[3][3] = {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}};
    int right[3][3] = {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}};
    int left[3][3] = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};
    int up[3][3] = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
    int down[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

    Cube cub(front, back, right, left, up, down);



    //cub.front_rotation_right();
    //cub.back_rotation_right();
    //cub.down_rotation_right();
    cub.right_rotation_up();


    std::cout << cub << "\n\n";

    //cub.right_rotation_up();
    cub.right_rotation_up();
    cub.back_rotation_left();

    assembling(cub);

    std::cout << cub << "\n\n";

    //std::cout << cub.down_cross_completed() << "\n\n";
    
}
