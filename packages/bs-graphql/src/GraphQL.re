type schema;
type schemaDefinition('a) = Js.t({..} as 'a);
type graphQLScalarType;

[@bs.new] [@bs.module "graphql"]
external schema: schemaDefinition('a) => schema = "GraphQLSchema";
[@bs.module "graphql"] external graphQLInt: graphQLScalarType = "GraphQLInt";
[@bs.module "graphql"]
external graphQLFloat: graphQLScalarType = "GraphQLFloat";
[@bs.module "graphql"]
external graphQLString: graphQLScalarType = "GraphQLString";
[@bs.module "graphql"]
external graphQLList: graphQLScalarType = "GraphQLString";
[@bs.module "graphql"]
external graphQLNonNull: graphQLScalarType => graphQLScalarType =
  "GraphQLNonNull";
[@bs.new] [@bs.module "graphql"]
external graphQLObj: Js.t({..}) => graphQLScalarType = "GraphQLObjectType";

type scalar(_) =
  | Int: scalar(option(int))
  | String: scalar(option(string))
  | Bool: scalar(option(bool))
  | Float: scalar(option(float))
  | List(scalar('a)): scalar(option(array('a)))
  | Obj(objDef('a)): scalar(option('a))
  | NonNull(scalar(option('a))): scalar('a)
and objDef('a) = {
  name: string,
  fields: 'a => array(fieldDef),
}
and field('context, 'root, 'a) = {
  name: string,
  typ_: scalar('a),
  resolver: ('root, 'context) => 'a,
}
and fieldDef =
  | Field(field('context, 'root, 'a)): fieldDef;

type user = {
  name: string,
  age: option(int),
  favoriteFruits: array(string),
};

let userSchemaType =
  Obj({
    name: "User",
    fields: _user => [|
      Field({
        name: "name",
        typ_: NonNull(String),
        resolver: (user, _) => user.name,
      }),
      Field({name: "age", typ_: Int, resolver: (user, _) => user.age}),
      Field({
        name: "favoriteFruits",
        typ_: NonNull(List(NonNull(String))),
        resolver: (user, _) => user.favoriteFruits,
      }),
    |],
  });

let schema = [|
  Obj({
    name: "Query",
    fields: _ => [|
      Field({
        name: "user",
        typ_: userSchemaType,
        resolver: (_, _) =>
          Some({
            name: "John Doe",
            age: Some(60),
            favoriteFruits: [|"apple"|],
          }),
      }),
    |],
  }),
|];
