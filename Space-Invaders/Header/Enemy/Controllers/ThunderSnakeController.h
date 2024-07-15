#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {

        class ThunderSnakeController : public EnemyController
        {
        private:
            float vertical_travel_distance = 100.f;
            float thunder_snake_rate_of_fire = 4.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();
            void moveUp();

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;
            void fireBullet();
        };
    }
}