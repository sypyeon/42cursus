#ifdef VECT2_HPP
#define VECT2_HPP

class vect2
{
private:
	int x;
	int y;
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();

	vect2 operator[](int i) const;
	vect2& operator[](int i);

	vect2 operator-() const;
	
	vect2 operator*(int num) const;
	vect2& operator*=(int num);

	vect2& operator+=(const vect2& other);
	vect2& operator-=(const vect2& other);
	vect2& operator*=(const vect2& other);

	vect2 operator+(const vect2& other) const;
	vect2 operator-(const vect2& other) const;
	vect2 operator*(const vect2& other) const;
	
}

#endif