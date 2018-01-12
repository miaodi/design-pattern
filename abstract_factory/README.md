# Abstract Factory

The __abstract factory pattern__ provides a way to encapsulate a group of individual factories that have a __common theme__ without specifying their concrete classes. In normal usage, the client solftware creates a concrete implementation of the abstract factory and then uses the generic interface of the factory to create the concrete objects that are part of the theme.

## Applicability

* A system should be independent of how its products are created, composed and represented.

* A system should be configured with one of multiple families of products.

* A family of related product objects is designed to be used together, and you need to enforce this constraint.

* You want to provide a class library of products, and you want to reveal just their interfaces, not their implemenetations. 