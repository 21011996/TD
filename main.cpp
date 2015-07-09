#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "shapes.h"
#include "labengine/labengine.h"

namespace 
{

struct MyWeb
{
	MyWeb(int width, int heigth, int size) : m_width(width), m_heigth(heigth), m_size(size) {};
	~MyWeb() {};

	void draw(int flag, int x, int y);

private :
	int m_width, m_heigth, m_size;
};

using namespace td;

void MyWeb::draw(int flag, int x, int y) {
	if (flag == 1) {
		MyRect square(0, 0, m_size, m_size);
		LabSetColor(LABCOLOR_WHITE);
		for (int i = 0; i < m_width; i++) {
			for (int j = 0; j < m_heigth; j++) {
				if (x == i && y == j) {
					LabSetColor(LABCOLOR_RED);
				} else {
					LabSetColor(LABCOLOR_WHITE);
				}
				square.draw(i*m_size,j*m_size);
			}
		}
	} else {
		MyRect square(0, 0, m_size, m_size);
		LabSetColor(LABCOLOR_RED);
		square.draw(x*m_size,y*m_size);
	}
}

struct Cursor
{
	Cursor(int x, int y, int x_limit, int y_limit) : m_x(x), m_y(y), m_x_limit(x_limit), m_y_limit(y_limit) {};
	void move(labkey_t key);

public :
	int m_x, m_y, m_x_limit, m_y_limit;
};

void Cursor::move(labkey_t key) {
	switch (key) 
	{
	case LABKEY_RIGHT :  
		{
			if (m_x < m_x_limit - 1) {
				m_x++;
			}
			break;
		}
	case LABKEY_DOWN :
		{
			if (m_y < m_y_limit - 1) {
				m_y++;
			}
			break;
		}
	case LABKEY_LEFT :
		{
			if (m_x > 0) {
				m_x--;
			}
			break;
		}
	case LABKEY_UP :
		{
			if (m_y > 0) {
				m_y--;
			}
			break;
		}
	}
}

struct MyPlacement
{
	MyPlacement(int x, int y, int a);
	~MyPlacement() { std::cout << "hi"; } 
	void update(float dt);

	int get_x() const { return int(m_x); }
	int get_y() const { return int(m_y); }

private :
	float m_x, m_y, m_a;
	float m_speed;
};

MyPlacement::MyPlacement(int x, int y, int a)
: m_x(float(x)), m_y(float(y)), m_a(float(a)), m_speed(0)
{
}

void MyPlacement::update(float dt) {
	m_speed += m_a * dt;
	m_y += m_speed * dt;
	if (m_y >= LabGetHeight() || m_y <= 0) {
		m_speed = -m_speed;
	}
}

void setRandomColor(){
	LabSetColorRGB(rand() % 255, rand() % 255, rand() % 255); 
}



template<class T>
std::shared_ptr<IDrawable> make_object(int a, int b, int c, int d) {
	return std::shared_ptr<IDrawable>(new T(a, b, c, d));
}

template<class T>
std::shared_ptr<IDrawable> make_object(int a, int b) {
	return std::shared_ptr<IDrawable>(new T(a, b));
}

} // namespace

int main()
{
	//std::shared_ptr<IDrawable> objects[] = {make_object<MyEllipse>(0, 0, 50, 50), make_object<MyEllipse>(100, 0, 50, 60), make_object<MyLine>(200, 0, 50, 50), make_object<MyPoint>(300, 0), make_object<MyRect>(400, 0, 50, 50)};
	//int num_objects = sizeof(objects) / sizeof(objects[0]);
	//
	//labparams_t lab = {1000, 800, 1};
	//LabInitWith(&lab);

	//float timePartition = 0.1f;
	//MyPlacement placement(150, 400, 10);
	//while (!LabInputKeyReady()) {

	//	LabClear();
	//	setRandomColor();
	//	placement.update(timePartition);

	//	//std::for_each(objects + rand() % 4, objects + num_objects, [&placement](std::shared_ptr<IDrawable> &p) {return p->draw(placement.get_x(), placement.get_y());});
	//	for (int i = rand() % 4; i != num_objects; ++i)
	//		objects[i]->draw(placement.get_x(), placement.get_y());

	//	LabDrawFlush();
	//	LabDelay(10);
	//}

	//LabInputKey();
	//LabTerm();

	labparams_t lab = {1000,800,1};
	LabInitWith(&lab);

	MyWeb web(10,8,100);
	Cursor cursor(0,0,10,8);
	int flag = 0;

	while (1) {
		LabClear();

		if (LabInputKeyReady())
		{
			labkey_t key = LabInputKey();
			if (key == LABKEY_ESC) {
				break;
			}
			if (key == LABKEY_ENTER) {
				flag = 1;
			}
			if (key == LABKEY_BACK) {
				flag = 0;
			}
			cursor.move(key);
		}
		web.draw(flag, cursor.m_x, cursor.m_y);
		
		LabDrawFlush();
	}

	LabTerm();
	return 0;
}