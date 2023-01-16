#include <iostream>

class Segment {
    double A, B;
public:
    Segment(double A, double B) : A(A), B(B) {}

    friend Segment operator+(double d, Segment seg) {
        seg.A = seg.A + d;
        seg.B = seg.B + d;
        return seg;
    }

    friend Segment operator+(Segment seg, double d) {
        seg.A = seg.A + d;
        seg.B = seg.B + d;
        return seg;
    }

    friend Segment operator+(Segment seg1, Segment seg2) {
        Segment segment{0, 0};
        if (seg2.A >= seg1.B && seg2.B >= seg1.B) {
            segment.A = seg1.A;
            segment.B = seg2.B;
        } else if (seg2.B <= seg1.A && seg2.A <= seg1.A) {
            segment.A = seg1.A;
            segment.B = seg2.B;
        } else if (seg1.B >= seg2.B && seg1.A <= seg2.A) {
            segment.A = seg2.A;
            segment.B = seg2.B;
        } else if (seg2.B >= seg1.B && seg2.A <= seg1.A) {
            segment.A = seg1.A;
            segment.B = seg1.B;
        } else if (seg1.A < seg2.A && seg1.B > seg2.A) {
            segment.A = seg2.A;
            segment.B = seg1.B;
        } else if (seg2.A < seg1.A && seg2.B > seg1.A) {
            segment.A = seg1.A;
            segment.B = seg2.B;
        }

        return segment;
    }

    friend Segment operator-(Segment seg, double d) {
        seg.A = seg.A - d;
        seg.B = seg.B - d;
        return seg;
    }

    friend Segment operator*(Segment seg, double d) {
        seg.A = seg.A * d;
        seg.B = seg.B * d;
        return seg;
    }

    friend Segment operator*(double d, Segment seg) {
        seg.A = seg.A * d;
        seg.B = seg.B * d;
        return seg;
    }

    friend Segment operator/(Segment seg, double d) {
        seg.A = seg.A / d;
        seg.B = seg.B / d;
        return seg;
    }

    bool operator()(double d) const {
        return d >= A && d <= B;
    }

    friend std::ostream &operator<<(std::ostream &, Segment &);
};

std::ostream &operator<<(std::ostream &str, Segment &segment) {
    return str << "[" << segment.A << "," << segment.B << "]";
}

int main() {
    using std::cout;
    using std::endl;
    Segment seg{2, 3}, s = 1 + 2 * ((seg - 2) / 2 + seg) / 3;
    //s = 1 + 2 * (({0,1} / 2 + {2,3})) / 3;
    //s = 1 + 2 * ({0,0.5} + {2,3}) / 3;
    //s = 1 + 2 * ({0,3}) / 3;
    //s = 1 + 2 * {0,1};
    //s = 1 + {0,2};
    //s = {1,3};
    cout << s << endl << std::boolalpha;
    for (double x = 0.5; x < 4; x += 1)
        cout << "x=" << x << ": " << s(x) << endl;
}
