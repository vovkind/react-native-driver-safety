declare type DriverSafetyType = {
    multiply(a: number, b: number): Promise<number>;
    enable(a: string): any;
    initialize(): any;
};
declare const _default: DriverSafetyType;
export default _default;
