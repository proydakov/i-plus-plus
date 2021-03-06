#pragma once

template<class key>
class hash_functor
{
};

template<>
class hash_functor<size_t>
{
public:
    size_t operator()(size_t k) const
    {
        return k;
    }
};

template<>
class hash_functor<int>
{
public:
    size_t operator()(int k) const
    {
        return static_cast<size_t>(k);
    }
};

template<>
class hash_functor<std::string>
{
public:
    size_t operator()(std::string const& k) const
    {
        size_t hash = 5381;
        for(size_t i = 0; i < k.size(); i++) {
            hash = ((hash << 5) + hash) + static_cast<size_t>(k[i]);
        }
        return hash;
    }
};
