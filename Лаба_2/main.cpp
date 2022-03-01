#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>


using namespace std;

// ВАРИАНТ 5

// Point - точка (содержит две координаты)
class Point {
private:
	double _x;
	double _y;

public:
	Point(double x = 0, double y = 0) : _x(x), _y(y)
	{
	}

	void setx(double value) { _x = value; }
	void sety(double value) { _y = value; }

	double x() const { return _x; }
	double y() const { return _y; }

	Point operator+=(const Point& other) {
		return Point(_x += other.x(), _y += other.y());
	}
};


class Figure {
public:


	virtual double center() const = 0;

	virtual void move() {};

	friend std::ostream& operator<<(std::ostream& out, const Figure& figure) {
		figure._write(out);
		return out;
	};

protected:
	virtual std::ostream& _write(std::ostream&) const = 0;
};

class Polygon : public Figure {
protected:
	std::vector<Point> _points;

public:
	Polygon(int vertices_count)
	{
		assert(vertices_count > 0);
		_points.resize(vertices_count);
	}

	Polygon(const std::initializer_list<Point>& list)
	{
		_points.resize(list.size());

		int i = 0;
		for (auto& init_point : list) {
			_points[i++] = init_point;
		}
	}

	std::vector<Point> points() const { return _points; }

	void move(const std::vector<Point>& by_points) {
		int i = 0;
		for (auto& point : _points) {
			point += by_points[i++];
		}
	}

	double center() const override
	{
    int count = _points.size();
    double X_sum = 0;
    double Y_sum = 0;
		for (int i=0; i<count; i++)
            {
			 int first_p = i % count;
			 X_sum += _points[first_p].x();
			 Y_sum += _points[first_p].y();
            }
    double X_center = X_sum / count;
    double Y_center = Y_sum / count;
    double Central_number = abs(X_sum) + abs(Y_sum);

  return Central_number;// Центр фигуры - [x, y]
};

private:
	std::ostream& _write(std::ostream& out) const override {
		int p_it = 1;
		for (const auto& point : _points) {
			out << "T" << p_it++ << "(" << point.x() << "; " << point.y() << ") ";
		}

		return out;
	}
};

// Factory - класс, который содержит массив фигур
class Factory {
private:
	std::vector<Figure*> _figures;

public:
	Factory()
	{
	}

	~Factory()
	{
		for (Figure* figure_pointer : _figures) {
			if (figure_pointer) delete figure_pointer;
		}
	}

	void pushBack(Figure* figure) {
		_figures.push_back(figure);
	}
	void pushFront(Figure* figure) {
		_figures.insert(_figures.begin(), figure);
	}
	void insertInto(Figure* figure, int position) {
		_figures.insert(_figures.begin() + position, figure);
	}

	void removeBack() {
		delete _figures[_figures.size() - 1];
		_figures.erase(_figures.end());
	}
	void removeFront() {
		delete _figures[0];
		_figures.erase(_figures.begin());
	}
	void removeBy(int index) {
		delete _figures[index];
		_figures.erase(_figures.begin() + index);
	}

	Figure* getLast() {
		return _figures[_figures.size() - 1];
	}
	Figure* getFirst() {
		return _figures[0];
	}
	Figure* get(int index) {
		return _figures[index];
	}

	Figure* getAlongClosestCenter() {
		int closest_i = 0;
		for (int i = 1; i < _figures.size(); i++) {
			if (_figures[i]->center() < _figures[closest_i]->center()) {
				closest_i = i;
			}
		}

		return _figures[closest_i];
	}

	void print() const {
		int f_it = 1;
		for (const Figure* figure : _figures) {
			std::cout << "Figure" << f_it++ << ": " << *figure << '\n';
		}
	}
};

int main() {

	Factory f;
	// Пятиугольник
	f.pushBack(new Polygon{
		Point(20, 0),
		Point(60, 20),
		Point(10, -10),
		Point(20, 0),
		Point(60, 20)
	});

	f.pushBack(new Polygon{
		Point(-5, 5),
		Point(15, 5),
		Point(15, -5),
		Point(-5, -5)
	});

	f.pushBack(new Polygon{
		Point(-2, 5),
		Point(5, 15),
		Point(35, -5)
	});

	f.print();

	cout << "\nThe Polygon which is closest to center:\n";
	cout << *(f.getAlongClosestCenter()) << "  P = " << f.getAlongClosestCenter()->center() << '\n';

	return 0;
}
