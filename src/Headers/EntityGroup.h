#pragma once

#include <vector>

#include "Entity.h"

using std::vector;
using glm::mat4;
using glm::vec3;

class EntityGroup {

private:
    vec3 pos, rot, scaleXYZ;
    vector<const Entity*> entities;
    vector<const EntityGroup*> childrenGroups;

public:
    EntityGroup();
    ~EntityGroup();
    explicit EntityGroup(const EntityGroup * src, bool copyTransform);

    EntityGroup * add(const Entity * entity);
    EntityGroup * add(const EntityGroup * group);
    EntityGroup * remove(const Entity * entity);
    EntityGroup * remove(const EntityGroup * group);

    EntityGroup * translate(const vec3 & translation);
    EntityGroup * rotate(const vec3 & rotation);
    EntityGroup * scale(const vec3 & scale);
    EntityGroup * scale(float scale);

    EntityGroup * set_translation(const vec3 & translation);
    EntityGroup * set_rotation(const vec3 & rotation);
    EntityGroup * set_scale(const vec3 & scale);
    EntityGroup * set_scale(float scale);

    mat4 create_transform() const;

    inline const vector<const Entity*> & get_entities() const {
        return entities;
    }

    inline const vector<const EntityGroup*> & get_children_groups() const {
        return childrenGroups;
    }

};
