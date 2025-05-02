// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"


// 1. Проверка большого радиуса
TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(c.getRadius(), 1e6, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 1e12, 1e-9);
}

// 2. Проверка нулевого радиуса
TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_NEAR(c.getRadius(), 0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0, 1e-9);
}

// 3. Проверка единичного радиуса
TEST(CircleTest, UnitRadius) {
    Circle c(1);
    EXPECT_NEAR(c.getRadius(), 1, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI, 1e-9);
}

// 4. Установка площади и пересчёт
TEST(CircleTest, SetArea) {
    Circle c(1);
    c.setArea(M_PI * 4);
    EXPECT_NEAR(c.getRadius(), 2, 1e-9);
    EXPECT_NEAR(c.getFerence(), 4 * M_PI, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 4, 1e-9);
}

// 5. Установка длины окружности и пересчёт
TEST(CircleTest, SetFerence) {
    Circle c(1);
    c.setFerence(2 * M_PI * 3);
    EXPECT_NEAR(c.getRadius(), 3, 1e-9);
    EXPECT_NEAR(c.getFerence(), 6 * M_PI, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 9, 1e-9);
}

// 6. Изменение радиуса
TEST(CircleTest, SetRadius) {
    Circle c(1);
    c.setRadius(5);
    EXPECT_NEAR(c.getRadius(), 5, 1e-9);
    EXPECT_NEAR(c.getFerence(), 10 * M_PI, 1e-9);
    EXPECT_NEAR(c.getArea(), 25 * M_PI, 1e-9);
}

// 7. Малая площадь
TEST(CircleTest, SmallArea) {
    Circle c(1);
    c.setArea(1e-12);
    EXPECT_NEAR(c.getArea(), 1e-12, 1e-18);
    EXPECT_NEAR(c.getRadius(), sqrt(1e-12 / M_PI), 1e-9);
}

// 8. Большая площадь
TEST(CircleTest, LargeArea) {
    Circle c(1);
    c.setArea(1e12);
    EXPECT_NEAR(c.getArea(), 1e12, 1e3);
    EXPECT_NEAR(c.getRadius(), sqrt(1e12 / M_PI), 1e-3);
}

// 9. Отрицательный радиус (ожидаем что будет как есть, без проверки ошибок)
TEST(CircleTest, NegativeRadius) {
    Circle c(-5);
    EXPECT_NEAR(c.getRadius(), -5, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * -5, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 25, 1e-9);
}

// 10. Проверка установки длины 0
TEST(CircleTest, ZeroFerence) {
    Circle c(1);
    c.setFerence(0);
    EXPECT_NEAR(c.getRadius(), 0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0, 1e-9);
}

// 11. Проверка площади через радиус
TEST(CircleTest, AreaFromRadius) {
    Circle c(3);
    EXPECT_NEAR(c.getArea(), M_PI * 9, 1e-9);
}

// 12. Проверка длины через радиус
TEST(CircleTest, FerenceFromRadius) {
    Circle c(3);
    EXPECT_NEAR(c.getFerence(), 6 * M_PI, 1e-9);
}

// 13. Проверка радиуса через площадь
TEST(CircleTest, RadiusFromArea) {
    Circle c(1);
    c.setArea(M_PI * 16);
    EXPECT_NEAR(c.getRadius(), 4, 1e-9);
}

// 14. Проверка радиуса через длину
TEST(CircleTest, RadiusFromFerence) {
    Circle c(1);
    c.setFerence(2 * M_PI * 7);
    EXPECT_NEAR(c.getRadius(), 7, 1e-9);
}

// 15. Площадь через длину
TEST(CircleTest, AreaFromFerence) {
    Circle c(1);
    c.setFerence(2 * M_PI * 4);
    EXPECT_NEAR(c.getArea(), M_PI * 16, 1e-9);
}

// 16. Малая длина
TEST(CircleTest, SmallFerence) {
    Circle c(1);
    c.setFerence(1e-6);
    EXPECT_NEAR(c.getFerence(), 1e-6, 1e-9);
    EXPECT_NEAR(c.getRadius(), 1e-6 / (2 * M_PI), 1e-9);
}

// 17. Проверка после нескольких изменений
TEST(CircleTest, MultipleChanges) {
    Circle c(1);
    c.setRadius(3);
    c.setFerence(2 * M_PI * 5);
    c.setArea(M_PI * 36);
    EXPECT_NEAR(c.getRadius(), 6, 1e-9);
    EXPECT_NEAR(c.getFerence(), 12 * M_PI, 1e-9);
    EXPECT_NEAR(c.getArea(), 36 * M_PI, 1e-9);
}

// 18. Граничное значение радиуса
TEST(CircleTest, BorderRadius) {
    Circle c(DBL_MAX);
    EXPECT_NEAR(c.getRadius(), DBL_MAX, 1e292); // из-за масштабов
}

// 19. Граничное значение площади
TEST(CircleTest, BorderArea) {
    Circle c(1);
    c.setArea(DBL_MAX);
    EXPECT_NEAR(c.getArea(), DBL_MAX, 1e292);
}

// 20. Малая площадь, граничное значение
TEST(CircleTest, TinyArea) {
    Circle c(1);
    c.setArea(DBL_MIN);
    EXPECT_NEAR(c.getArea(), DBL_MIN, 1e-308);
}
