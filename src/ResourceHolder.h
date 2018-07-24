#ifndef __RESOURCE_HOLDER_H__
#define __RESOURCE_HOLDER_H__

#include <string>
#include <map>
#include <cassert>
#include <memory>

#include "ResourceIdentifiers.h"

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void load(Identifier id, const std::string& filename);
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;
    template<typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& parameter);

private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceHolder.inl"
#endif __RESOURCE_HOLDER_H__
