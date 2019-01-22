open Jest;

test("miscellaneous float", () =>
  Expect.(
    expect(
      {
        open! BigNumber;
        ((bignumber(Float, 10.0) +. 10.0) /. 5.0)->toFloat;
      },
    )
    |> toBe(4.0)
  )
);

test("miscellaneous int", () =>
  Expect.(
    expect(
      {
        open! BigNumber;
        ((bignumber(Int, 10) + 10) / 5)->toInt;
      },
    )
    |> toBe(4)
  )
);

describe("plus", () =>
  test("float", () =>
    Expect.(
      expect(
        {
          open! BigNumber;
          (bignumber(Float, 0.1) +. 0.2)->toFloat;
        },
      )
      |> toBe(0.3)
    )
  )
);

describe("times", () =>
  test("float", () =>
    Expect.(
      expect(
        {
          open! BigNumber;
          (bignumber(Float, 0.199) *. 0.2)->toFloat;
        },
      )
      |> toBe(0.0398)
    )
  )
);
